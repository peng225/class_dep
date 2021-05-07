#include "der_sample.h"

DerSample::DerSample() : fuga(0)
{
}

int DerSample::addValAndGet(int addVal)
{
    return getVal() + addVal + fuga;
}


