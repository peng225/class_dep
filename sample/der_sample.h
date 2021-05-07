#ifndef DER_SAMPLE_H
#define DER_SAMPLE_H

#include "sample.h"

class DerSample : public Sample
{
public:
    DerSample();
    virtual int addValAndGet(int addVal) override;
private:
    int fuga;
};

#endif

