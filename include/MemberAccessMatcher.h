#ifndef MEMBER_ACCESS_MATCHER
#define MEMBER_ACCESS_MATCHER
#include "clang/ASTMatchers/ASTMatchers.h"
#include "clang/ASTMatchers/ASTMatchFinder.h"
#include <string>

using namespace clang;
using namespace clang::ast_matchers;

class MemberAccessMatcher
{
public :
    MemberAccessMatcher(std::string targetName);
    StatementMatcher getMatcher();

private:
    StatementMatcher matcher;
};

#endif

