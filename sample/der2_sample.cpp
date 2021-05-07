#include "der2_sample.h"

using namespace test;

Der2Sample::Der2Sample() : piyo(0)
{
}

int Der2Sample::addValAndGet(int addVal)
{
    return getVal() + addVal + piyo;
}


