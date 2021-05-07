#include "../include/FieldInfoExtractor.h"


std::string FieldInfoExtractor::getClassName(const clang::FieldDecl &node)
{
    return node.getParent()->getNameAsString();
}

