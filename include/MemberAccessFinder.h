#ifndef MEMBER_ACCESS_FINDER
#define MEMBER_ACCESS_FINDER
#include "../include/Target.h"
#include "clang/ASTMatchers/ASTMatchers.h"
#include "clang/ASTMatchers/ASTMatchFinder.h"
#include <memory>


class MemberAccessFinder : public clang::ast_matchers::MatchFinder::MatchCallback {
public :
    MemberAccessFinder(std::shared_ptr<Target> tgt);
    virtual void run(const clang::ast_matchers::MatchFinder::MatchResult &result);

private:
    std::shared_ptr<Target> tgt;

    bool shouldUseNode(clang::CXXMethodDecl &decl);
    bool shouldUseNode(clang::FieldDecl &decl);
};

#endif

