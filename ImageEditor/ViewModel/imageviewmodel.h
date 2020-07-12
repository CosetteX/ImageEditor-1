#ifndef IMAGEVIEWMODEL_H
#define IMAGEVIEWMODEL_H

#include "../Common/image.h"
#include "../Common/notification.h"
#include "../Model/imagemodel.h"
#include "command.h"

class ImageViewModel:public INotifyPropertyChanged
{
private:
    std::shared_ptr<ImageModel> _ImageModel;    //image 实体对象
    std::shared_ptr<cmdGray> cmd_Gray;

public:
    ImageViewModel();

    //get/set model
    std::shared_ptr<ImageModel> getImageModel();
    void setImageModel(std::shared_ptr<ImageModel>& imgModel);

    //get Image attribute
    std::shared_ptr<Image> getImage();

    //get command
    std::shared_ptr<ICommandBase> getOpen();
    std::shared_ptr<ICommandBase> getClose();
    std::shared_ptr<ICommandBase> getSave();
    std::shared_ptr<ICommandBase> getSaveAs();
    std::shared_ptr<ICommandBase> getZoomIn();
    std::shared_ptr<ICommandBase> getZoomOut();
    std::shared_ptr<ICommandBase> getRotate();
    std::shared_ptr<ICommandBase> getGray();
    std::shared_ptr<ICommandBase> getBlur();
    std::shared_ptr<ICommandBase> getSharp();

    //bind property
    INotifyPropertyChanged getPropertyNotification();
};

#endif // IMAGEVIEWMODEL_H
