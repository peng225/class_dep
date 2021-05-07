#ifndef METHOD_MATCHER
#define METHOD_MATCHER
#include "clang/ASTMatchers/ASTMatchers.h"
#include "clang/ASTMatchers/ASTMatchFinder.h"
#include <string>

using namespace clang;
using namespace clang::ast_matchers;

class MethodMatcher
{
public :
    MethodMatcher(std::string targetName);
    DeclarationMatcher getMatcher();

private:
    DeclarationMatcher matcher;
};

#endif

