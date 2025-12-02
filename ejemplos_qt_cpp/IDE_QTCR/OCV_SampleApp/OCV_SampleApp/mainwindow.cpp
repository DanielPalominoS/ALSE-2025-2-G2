#include "mainwindow.h"
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QFileDialog>
#include <QPixmap>
#include <QImage>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent) {

    // Initialize widgets
    originalImageLabel = new QLabel("Original Image");
    processedImageLabel = new QLabel("Processed Image");

    thresholdSlider1 = new QSlider(Qt::Horizontal);
    thresholdSlider2 = new QSlider(Qt::Horizontal);
    operationComboBox = new QComboBox();
    loadButton = new QPushButton("Load Image");

    // Configure sliders
    thresholdSlider1->setRange(0, 255);
    thresholdSlider2->setRange(0, 255);
    thresholdSlider1->setValue(100);
    thresholdSlider2->setValue(200);

    // Add options
    operationComboBox->addItems({"Edge Detection", "Dilation", "Erosion"});

    // Layout setup
    auto *mainWidget = new QWidget(this);
    auto *mainLayout = new QHBoxLayout();
    auto *controlLayout = new QVBoxLayout();
    auto *imageLayout = new QHBoxLayout();

    // Image sections with titles
    auto *leftImageLayout = new QVBoxLayout();
    leftImageLayout->addWidget(new QLabel("Original"));
    leftImageLayout->addWidget(originalImageLabel);

    auto *rightImageLayout = new QVBoxLayout();
    rightImageLayout->addWidget(new QLabel("Processed"));
    rightImageLayout->addWidget(processedImageLabel);

    imageLayout->addLayout(leftImageLayout);
    imageLayout->addLayout(rightImageLayout);

    // Control panel (acts like collapsible/foldable menu)
    controlLayout->addWidget(operationComboBox);
    controlLayout->addWidget(thresholdSlider1);
    controlLayout->addWidget(thresholdSlider2);
    controlLayout->addWidget(loadButton);

    // Assemble main layout
    mainLayout->addLayout(controlLayout);
    mainLayout->addLayout(imageLayout);
    mainWidget->setLayout(mainLayout);
    setCentralWidget(mainWidget);

    // Signal-slot connections
    connect(loadButton, &QPushButton::clicked, this, &MainWindow::loadImage);
    connect(thresholdSlider1, &QSlider::valueChanged, this, &MainWindow::updateThreshold);
    connect(thresholdSlider2, &QSlider::valueChanged, this, &MainWindow::updateThreshold);
}

MainWindow::~MainWindow() {}

void MainWindow::loadImage() {
    QString filePath = QFileDialog::getOpenFileName(this, "Open Image", "", "Images (*.png *.jpg *.bmp)");
    if (!filePath.isEmpty() && processor.loadImage(filePath)) {
        applyProcessing();
    }
}


void MainWindow::updateThreshold(int) {
    applyProcessing();
}

void MainWindow::applyProcessing() {
    processedImage = processor.process(operationComboBox->currentText().toStdString(),
                                       thresholdSlider1->value(),
                                       thresholdSlider2->value());
    updateImageViews();
}

void MainWindow::updateImageViews() {
    cv::Mat originalImage = processor.getOriginalImage();
    if (originalImage.empty()) return;
    cv::Mat origRGB, procRGB;

    // Convert to RGB for QImage
    if (originalImage.channels() == 3)
        cv::cvtColor(originalImage, origRGB, cv::COLOR_BGR2RGB);
    else
        cv::cvtColor(originalImage, origRGB, cv::COLOR_GRAY2RGB);

    if (processedImage.channels() == 1)
        cv::cvtColor(processedImage, procRGB, cv::COLOR_GRAY2RGB);
    else
        cv::cvtColor(processedImage, procRGB, cv::COLOR_BGR2RGB);

    originalImageLabel->setPixmap(QPixmap::fromImage(cvMatToQImage(origRGB)).scaled(300, 300, Qt::KeepAspectRatio));
    processedImageLabel->setPixmap(QPixmap::fromImage(cvMatToQImage(procRGB)).scaled(300, 300, Qt::KeepAspectRatio));
}

QImage MainWindow::cvMatToQImage(const cv::Mat &mat) {
    return QImage(mat.data, mat.cols, mat.rows, mat.step, QImage::Format_RGB888).copy();
}
