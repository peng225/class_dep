#ifndef MEMBER_ACCESS_MATCHER
#define MEMBER_ACCESS_MATCHER
#include "clang/ASTMatchers/ASTMatchers.h"
#include "clang/ASTMatchers/ASTMatchFinder.h"
#include <string>


class MemberAccessMatcher
{
public :
    MemberAccessMatcher(std::string targetName);
    clang::ast_matchers::StatementMatcher getMatcher();

private:
    clang::ast_matchers::StatementMatcher matcher;
};

#endif

