#ifndef TARGET
#define TARGET

#include <string>
#include <vector>

class Target
{
public:
    Target(std::string name);
    std::string getName();
    std::vector<std::string> getNames();
    void add(const std::string &newName);

private:
    std::vector<std::string> names;
};

#endif
