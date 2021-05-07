#include "der2_sample.h"
#include <iostream>

int main()
{
    Sample s;
    s.setVal(10);
    std::cout << s.getVal() << std::endl;

    Sample *ds = new DerSample;
    ds->setVal(12);
    std::cout << ds->addValAndGet(2) << std::endl;
    delete ds;

    DerSample *ds2 = new test::Der2Sample;
    ds2->setVal(12);
    std::cout << ds2->addValAndGet(2) << std::endl;
    delete ds2;

    return 0;
}

