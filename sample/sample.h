#ifndef SAMPLE_H
#define SAMPLE_H

class Sample
{
public:
    Sample();
    void setVal(int i);
    int getVal();
    virtual int addValAndGet(int addVal);
    int trivial();
protected:
    int hoge;
};

#endif

