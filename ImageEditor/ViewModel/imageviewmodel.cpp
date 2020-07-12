#include "imageviewmodel.h"
#include "../Model/imagemodel.h"

ImageViewModel::ImageViewModel()
{

}


void ImageViewModel::SetModel(std::shared_ptr<ImageModel> model)
{
    imageModel = model;
}

void ImageViewModel::ExecOpenFileCommand(const std::string &path)
{
    imageModel->OpenFile(path);
}

void ImageViewModel::ExecSaveFileCommand(const std::string &path)
{
    imageModel->SaveFile(path);
}

void ImageViewModel::ExecSharpCommand()
{
    imageModel->Sharp();
}

void ImageViewModel::ExecGrayCommand()
{
    imageModel->Gray();
}

void ImageViewModel::ExecBlurCommand(int ksize, int anchor)
{
    imageModel->Blur(ksize, anchor);
}

