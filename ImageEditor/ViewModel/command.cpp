#include "command.h"
#include "imageviewmodel.h"

void cmdGray::SetParameter(const Parameters& param)
{
    //this->param = param;
}

void cmdGray::Exec()
{
    p_ImageModel->getGray();
}
