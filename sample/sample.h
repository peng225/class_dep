#ifndef SAMPLE_H
#define SAMPLE_H

class Sample
{
public:
    Sample();
    void setVal(int i);
    int getVal();
    int addValAndGet(int addVal);
    int trivial();
private:
    int hoge;
};

#endif

