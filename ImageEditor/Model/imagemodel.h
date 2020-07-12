#ifndef IMAGEMODEL_H
#define IMAGEMODEL_H

#include <memory>

#include "../Common/image.h"
#include "../Common/notification.h"

#include <opencv2/core/core.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>

class ImageModel:public INotifyPropertyChanged
{
private:
    std::shared_ptr<Image> mImage;   //Image 对象

public:
    ImageModel();

    //get property
    std::shared_ptr<Image> get_Image();

    //command
    void Open(QString path);
    void Close();
    void Save();
    void SaveAs(QString path);

    void ZoomIn();
    void ZoomOut();
    void Rotate();

    void Gray();
    void Blur();
    void Sharp();


};

#endif // IMAGEMODEL_H
