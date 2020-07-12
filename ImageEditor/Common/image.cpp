#include "image.h"

Image::Image()
{

}

void Image::Sharp()
{
    Mat sharpkernel = (Mat_<float>(3, 3) <<
                0, -1, 0,
                -1,10, -1,
                0, -1, 0);
    filter2D(this->currentImage,this->currentImage, CV_8UC1, sharpkernel);
}

void Image::Gray()
{
    cvtColor(this->currentImage,this->currentImage,COLOR_BGR2GRAY);
}

void Image::Blur()
{

    blur(this->currentImage, this->currentImage, Size(5,5));
}
