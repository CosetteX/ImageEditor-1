#ifndef PARAMETERS_H
#define PARAMETERS_H
#include <QObject>
class Parameters
{
public:
    Parameters();
};

class pathParameters:public Parameters
{
private:
    QString filepath;
public:
    pathParameters(QString newPath):filepath(newPath){}
    QString getPath()
    {
        return filepath;
    }
};


#endif // PARAMETERS_H
