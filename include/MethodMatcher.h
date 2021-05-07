#ifndef METHOD_MATCHER
#define METHOD_MATCHER
#include "clang/ASTMatchers/ASTMatchers.h"
#include "clang/ASTMatchers/ASTMatchFinder.h"
#include <string>


class MethodMatcher
{
public :
    MethodMatcher(std::string targetName);
    clang::ast_matchers::DeclarationMatcher getMatcher();

private:
    clang::ast_matchers::DeclarationMatcher matcher;
};

#endif

