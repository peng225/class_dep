#ifndef BASES_FINDER
#define BASES_FINDER
#include "../include/Target.h"
#include "clang/ASTMatchers/ASTMatchers.h"
#include "clang/ASTMatchers/ASTMatchFinder.h"
#include <string>
#include <memory>


class BasesFinder : public clang::ast_matchers::MatchFinder::MatchCallback {
public:
    BasesFinder(std::shared_ptr<Target> tgt);
    virtual void run(const clang::ast_matchers::MatchFinder::MatchResult &result) override;

private: 
    std::shared_ptr<Target> tgt;
};

#endif

