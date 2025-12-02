#include "imageprocessor.h"

bool ImageProcessor::loadImage(const QString &path) {
    originalImage = cv::imread(path.toStdString());
    return !originalImage.empty();
}

cv::Mat ImageProcessor::getOriginalImage() const {
    return originalImage;
}

cv::Mat ImageProcessor::process(const std::string &operation, int thresh1, int thresh2) {
    cv::Mat result;
    if (originalImage.empty()) return result;

    if (operation == "Edge Detection") {
        cv::Canny(originalImage, result, thresh1, thresh2);
    } else if (operation == "Dilation") {
        auto kernel = cv::getStructuringElement(cv::MORPH_RECT, {3, 3});
        cv::dilate(originalImage, result, kernel);
    } else if (operation == "Erosion") {
        auto kernel = cv::getStructuringElement(cv::MORPH_RECT, {3, 3});
        cv::erode(originalImage, result, kernel);
    }

    return result;
}
