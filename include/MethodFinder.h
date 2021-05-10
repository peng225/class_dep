#ifndef METHOD_FINDER
#define METHOD_FINDER
#include "clang/ASTMatchers/ASTMatchers.h"
#include "clang/ASTMatchers/ASTMatchFinder.h"


class MethodFinder : public clang::ast_matchers::MatchFinder::MatchCallback {
public:
    virtual void run(const clang::ast_matchers::MatchFinder::MatchResult &result) override;
};

#endif

