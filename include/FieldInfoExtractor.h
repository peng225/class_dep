#ifndef FIELD_INFO_EXTRACTOR
#define FIELD_INFO_EXTRACTOR

#include "clang/AST/ASTContext.h"
#include "clang/ASTMatchers/ASTMatchFinder.h"
#include <string>

class FieldInfoExtractor {
public :
    std::string getClassName(const clang::FieldDecl &node);
};

#endif

