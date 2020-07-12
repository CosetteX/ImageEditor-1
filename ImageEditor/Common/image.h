#ifndef IMAGE_H
#define IMAGE_H

#include <QStack>
#include <QMessageBox>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>

using namespace cv;

class Image
{
public:
    Image();
public:
    QString filename;
    Mat originImage;
    Mat currentImage;

};

#endif // IMAGE_H
