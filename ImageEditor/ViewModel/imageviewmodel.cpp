#include "imageviewmodel.h"

ImageViewModel::ImageViewModel():_ImageModel(nullptr)
{
    cmd_Gray = std::make_shared<cmdGray>(this);
}

//get/set model
void ImageViewModel::setImageModel(std::shared_ptr<ImageModel>& imgModel)
{
    _ImageModel = imgModel;
}

std::shared_ptr<ImageModel> ImageViewModel::getImageModel()
{
    return _ImageModel;
}


//get Image attribute
std::shared_ptr<Image> ImageViewModel::getImage()
{
    return _ImageModel->get_Image();
}

//get command
std::shared_ptr<ICommandBase> ImageViewModel::getGray()
{
    return std::static_pointer_cast<ICommandBase>(cmd_Gray);
}

//std::shared_ptr<ICommandBase> ImageViewModel::getBlur();
//std::shared_ptr<ICommandBase> ImageViewModel::getSharp();

////bind property
//INotifyPropertyChanged ImageViewModel::getPropertyNotification();
