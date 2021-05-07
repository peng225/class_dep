#include "../include/BasesFinder.h"
#include "../include/MethodInfoExtractor.h"
#include "clang/AST/ASTContext.h"
#include <iostream>
#include <string>

using namespace clang;
using namespace clang::ast_matchers;

BasesFinder::BasesFinder(std::shared_ptr<Target> tgt)
    : tgt(tgt)
{
}

void BasesFinder::run(const MatchFinder::MatchResult &result) {
    ASTContext *context = result.Context;
    MethodInfoExtractor fie;
    if(auto *node = result.Nodes.getNodeAs<clang::CXXRecordDecl>("class")) {
        for(auto itr = node->bases_begin(); itr != node->bases_end(); itr++) {
            auto recDecl = ((itr->getType()).getTypePtr())->getAsCXXRecordDecl();
            auto className = recDecl->getNameAsString();
            tgt->add(className);
        }
    }
}

