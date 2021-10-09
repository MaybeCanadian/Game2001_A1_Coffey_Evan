#pragma once
#include "BaseArray.h"

template<class T>
class UnorderedList :
    public BaseArray<T>
{
public:
    UnorderedList(int size) : BaseArray<T>(size) {};
};