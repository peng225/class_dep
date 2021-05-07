#ifndef TARGET
#define TARGET

#include <string>

class Target
{
public:
    Target(std::string name);
    std::string getName();

private:
    std::string name;
};

#endif
