#ifndef FUNC_INFO_EXTRACTOR
#define FUNC_INFO_EXTRACTOR

#include "clang/AST/ASTContext.h"
#include "clang/ASTMatchers/ASTMatchFinder.h"
#include <string>

using namespace clang;
using namespace clang::ast_matchers;


class FuncInfoExtractor {
public :
    std::string extractFuncName(const clang::CXXMethodDecl &node);
    std::string getClassName(const clang::CXXMethodDecl &node);
};

#endif

