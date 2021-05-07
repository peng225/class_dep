#ifndef METHOD_FINDER
#define METHOD_FINDER
#include "clang/ASTMatchers/ASTMatchers.h"
#include "clang/ASTMatchers/ASTMatchFinder.h"

using namespace clang;
using namespace clang::ast_matchers;

extern DeclarationMatcher methodMatcher;

class MethodFinder : public MatchFinder::MatchCallback {
public :
    virtual void run(const MatchFinder::MatchResult &result);
};

#endif

