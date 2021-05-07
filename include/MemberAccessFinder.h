#ifndef MEMBER_ACCESS_FINDER
#define MEMBER_ACCESS_FINDER
#include "../include/Target.h"
#include "clang/ASTMatchers/ASTMatchers.h"
#include "clang/ASTMatchers/ASTMatchFinder.h"
#include <memory>

using namespace clang;
using namespace clang::ast_matchers;

class MemberAccessFinder : public MatchFinder::MatchCallback {
public :
    MemberAccessFinder(std::shared_ptr<Target> tgt);
    virtual void run(const MatchFinder::MatchResult &result);

private:
    std::shared_ptr<Target> tgt;
};

#endif

