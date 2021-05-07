#include "../include/BasesMatcher.h"
#include "clang/AST/ASTContext.h"

using namespace clang::ast_matchers;

BasesMatcher::BasesMatcher(std::string targetName) :
    matcher(cxxRecordDecl(isDefinition(), hasName(targetName)).bind("class"))
{
}

DeclarationMatcher BasesMatcher::getMatcher()
{
    return matcher;
}

