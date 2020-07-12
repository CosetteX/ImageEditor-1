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
    //this->ImgShow();
}

void Image::Gray()
{
    //PushStack();
    //isGray=true;
    cvtColor(this->currentImage,this->currentImage,COLOR_BGR2GRAY);
    //this->ImgShow();
}

void Image::Blur()
{
    //PushStack();
    //isBlur-true;
    blur(this->currentImage, this->currentImage, Size(5,5));
    //this->ImgShow();
}
