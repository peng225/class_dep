#include "../include/MethodMatcher.h"
#include "clang/AST/ASTContext.h"

MethodMatcher::MethodMatcher(std::string targetName) :
    matcher(cxxMethodDecl(isDefinition(), isExpansionInMainFile(), ofClass(hasName(targetName))).bind("methods"))
{
}

DeclarationMatcher MethodMatcher::getMatcher()
{
    return matcher;
}

