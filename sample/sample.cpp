#include "sample.h"

Sample::Sample() : hoge(0)
{
}

void Sample::setVal(int i)
{
    hoge = i;
}

int Sample::getVal()
{
    return hoge;
}


int Sample::addValAndGet(int addVal)
{
    return getVal() + hoge + addVal;
}


int Sample::trivial()
{
    return 5;
}

