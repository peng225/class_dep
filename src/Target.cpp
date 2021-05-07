#include "../include/Target.h"


Target::Target(std::string name)
{
    add(name);
}

std::string Target::getName()
{
    return names.front();
}

std::vector<std::string> Target::getNames()
{
    return names;
}


void Target::add(const std::string &newName)
{
    names.emplace_back(newName);
}

