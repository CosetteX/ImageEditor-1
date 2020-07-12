#ifndef COMMAND_H
#define COMMAND_H

#include "../Common/notification.h"
#include "../Common/Parameters.h"
class ImageViewModel;

class cmdGray:public ICommandBase
{
private:
    ImageViewModel* p_ImageModel;
    //Parameters param;
public:
    cmdGray(ImageViewModel* ptr):p_ImageModel(ptr){}
    void SetParameter(const Parameters &param) override;   //应该用来给命令传参数?
    void Exec() override;
};

#endif // COMMAND_H
