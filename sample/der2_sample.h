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

class Toy2
{
public:
    void hello2(){}
};


//class Der2Sample : public DerSample
class Der2Sample : public DerSample, public Toy, public virtual Toy2
{
public:
    Der2Sample();
    virtual int addValAndGet(int addVal) override;
private:
    int piyo;
};

}

#endif

