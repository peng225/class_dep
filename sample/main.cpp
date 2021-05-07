#include "sample.h"
#include <iostream>

int main()
{
    Sample s;
    s.setVal(10);
    std::cout << s.getVal() << std::endl;
    return 0;
}
