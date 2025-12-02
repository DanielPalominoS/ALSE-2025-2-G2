#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "imageprocessor.h"
#include <QMainWindow>
#include <QLabel>
#include <QSlider>
#include <QComboBox>
#include <QPushButton>
#include <opencv2/opencv.hpp>

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void loadImage();
    void applyProcessing();
    void updateThreshold(int);

private:
    QLabel *originalImageLabel;
    QLabel *processedImageLabel;
    QSlider *thresholdSlider1;
    QSlider *thresholdSlider2;
    QComboBox *operationComboBox;
    QPushButton *loadButton;

    ImageProcessor processor;
    cv::Mat processedImage;


    void updateImageViews();
    QImage cvMatToQImage(const cv::Mat &mat);
};

#endif // MAINWINDOW_H
