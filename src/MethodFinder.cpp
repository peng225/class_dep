#include "../include/MethodFinder.h"
#include "../include/FuncInfoExtractor.h"
#include "clang/AST/ASTContext.h"
#include <iostream>
#include <string>

using namespace clang;
using namespace clang::ast_matchers;

void MethodFinder::run(const MatchFinder::MatchResult &result) {
    ASTContext *context = result.Context;
    FuncInfoExtractor fie;
    if(auto *node = result.Nodes.getNodeAs<clang::CXXMethodDecl>("methods")) {
        auto method = fie.extractFuncName(*node);
        std::cout << "method = \"" << method << "\"" << std::endl;
    }
}

