#ifndef IMAGEVIEWMODEL_H
#define IMAGEVIEWMODEL_H

#include "../Common/etl.h"

class ImageModel;

class ImageViewModel : public Proxy_CommandNotification<ImageViewModel>
{
public:
    ImageViewModel();

    // TODO: Add Command
    void SetModel(std::shared_ptr<ImageModel> model);
    void ExecOpenFileCommand(const std::string &path);
    void ExecSaveFileCommand(const std::string &path);
    void ExecSharpCommand();
    void ExecGrayCommand();
    void ExecBlurCommand(int ksize = 3, int anchor = -1);
private:
    std::shared_ptr<ImageModel> imageModel;
};

#endif // IMAGEVIEWMODEL_H
