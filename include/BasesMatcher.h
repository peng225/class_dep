#ifndef BASES_MATCHER
#define BASES_MATCHER
#include "clang/ASTMatchers/ASTMatchers.h"
#include "clang/ASTMatchers/ASTMatchFinder.h"
#include <string>


class BasesMatcher
{
public :
    BasesMatcher(std::string targetName);
    clang::ast_matchers::DeclarationMatcher getMatcher();

private:
    clang::ast_matchers::DeclarationMatcher matcher;
};

#endif

