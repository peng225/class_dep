#ifndef DER2_SAMPLE_H
#define DER2_SAMPLE_H

#include "der_sample.h"

namespace test
{

class Toy
{
public:
    void hello(){}
};

//class Der2Sample : public DerSample
class Der2Sample : public DerSample, Toy
{
public:
    Der2Sample();
    virtual int addValAndGet(int addVal) override;
private:
    int piyo;
};

}

#endif

