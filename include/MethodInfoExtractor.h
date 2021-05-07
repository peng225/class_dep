#ifndef METHOD_INFO_EXTRACTOR
#define METHOD_INFO_EXTRACTOR

#include "clang/AST/ASTContext.h"
#include "clang/ASTMatchers/ASTMatchFinder.h"
#include <string>

class MethodInfoExtractor {
public :
    std::string extractFuncName(const clang::CXXMethodDecl &node);
    std::string getClassName(const clang::CXXMethodDecl &node);
};

#endif

