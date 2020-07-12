#include "imagemodel.h"

using namespace  std;
using namespace cv;

ImageModel::ImageModel()
{

}

void ImageModel::OpenFile(const std::string &path)
{
    // TODO: notify command
    originImage = imread(path);
    currentImage = originImage.clone();
}

void ImageModel::SaveFile(const string &path)
{
    // TODO: notify command
    imwrite(path, currentImage);
}

void ImageModel::Sharp()
{
    Mat sharpkernel = (Mat_<float>(3, 3) <<
                       0, -1, 0,
                       -1,10, -1,
                       0, -1, 0);
    filter2D(currentImage, currentImage, CV_8UC1, sharpkernel);
}

void ImageModel::Gray()
{
    cvtColor(currentImage, currentImage, COLOR_BGR2GRAY);
}

void ImageModel::Blur(int ksize, int anchor)
{
    blur(currentImage, currentImage, Size(ksize, ksize), Point(anchor, anchor));
}

