#include "../include/Target.h"


Target::Target(std::string name) : name(name)
{
}

std::string Target::getName()
{
    return name;
}
