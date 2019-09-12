#pragma once
#include "IPing.cpp"
class IConnect: public IPing{
    public:
    virtual bool network_connectable(int) = 0;
};