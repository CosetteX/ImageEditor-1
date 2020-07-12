#include "imagemodel.h"
#include <QMainWindow>
#include <QFileDialog>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QStack>
#include <QMessageBox>
#include <QDebug>
ImageModel::ImageModel()
{
    this->mImage = std::make_shared<Image>();
}

std::shared_ptr<Image> ImageModel::get_Image()
{
    return this->mImage;
}

void ImageModel::Open(QString path)
{
    mImage->filename = path;
}

void ImageModel::Close()
{
    mImage->filename = "";
    (mImage->currentImage).~Mat();
    (mImage->originImage).~Mat();
}

void ImageModel::Save()
{
    mImage->currentImage.copyTo(mImage->originImage);
}

void ImageModel::SaveAs(QString path)
{
    mImage->filename = path;
    mImage->currentImage.copyTo(mImage->originImage);
}

void ImageModel::ZoomIn()
{
    cv::resize(mImage->currentImage, mImage->currentImage, Size(mImage->currentImage.cols*1.5, mImage->currentImage.rows*1.5), INTER_LINEAR);
}
void ImageModel::ZoomOut()
{
    cv::resize(mImage->currentImage, mImage->currentImage, Size(mImage->currentImage.cols*0.75, mImage->currentImage.rows*0.75), INTER_LINEAR);
}
void ImageModel::Rotate()
{
    if(mImage->currentImage.empty()){
        qDebug()<<"RotateMat src is empty!";
    }

    transpose(mImage->currentImage, mImage->currentImage);
    flip(mImage->currentImage, mImage->currentImage, 1);
    qDebug()<<"rotate image";
}

void ImageModel::Sharp()
{
    Mat sharpkernel = (Mat_<float>(3, 3) <<
                0, -1, 0,
                -1,10, -1,
                0, -1, 0);
    filter2D(mImage->currentImage,mImage->currentImage, CV_8UC1, sharpkernel);
}

void ImageModel::Gray()
{
    cvtColor(mImage->currentImage,mImage->currentImage,COLOR_BGR2GRAY);
}

void ImageModel::Blur()
{

    blur(mImage->currentImage, mImage->currentImage, Size(5,5));
}
