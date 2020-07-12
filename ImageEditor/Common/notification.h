////////////////////////////////////////////////////////////////////////////////
#pragma once
////////////////////////////////////////////////////////////////////////////////

#include <cassert>
#include <cstdint>

#include <memory>
#include <any>
#include <vector>
#include <map>
#include <stack>
#include <array>
#include <string>

//types
typedef unsigned char  uchar;

//command

//属性发生改变
class IPropertyNotification
{
public:
    virtual void OnPropertyChanged(const std::string& str) = 0;
};

//命令完成  先不用它
class ICommandCompleted
{
public:
    virtual void OnCommandCompleted(const std::string& str) = 0;
};

class INotifyPropertyChanged
{
    void ClearNotification() noexcept
    {
        p_array.clear();
    }
    void AddNotification(const std::shared_ptr<IPropertyNotification>& ptr)
    {
        p_array.push_back(ptr);
    }
    void RemoveNotification(uintptr_t u) noexcept;

    void Fire(const std::string& str)
    {
        auto iter(p_array.begin());
        for(;iter != p_array.end();++iter)
        {
            (*iter)->OnPropertyChanged(str);
        }

    }

protected:
    std::vector<std::shared_ptr<IPropertyNotification>> p_array;
};
