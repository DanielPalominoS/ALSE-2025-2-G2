#ifndef IMAGEPROCESSOR_H
#define IMAGEPROCESSOR_H

#include <opencv4/opencv2/opencv.hpp>
//#include <opencv2/opencv.hpp>
#include <QString>

class ImageProcessor {
public:
    bool loadImage(const QString &path);
    cv::Mat getOriginalImage() const;
    cv::Mat process(const std::string &operation, int thresh1, int thresh2);

private:
    cv::Mat originalImage;
};

#endif // IMAGEPROCESSOR_H
