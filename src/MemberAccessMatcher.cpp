#include "../include/MemberAccessMatcher.h"
#include "clang/AST/ASTContext.h"

using namespace clang::ast_matchers;

MemberAccessMatcher::MemberAccessMatcher(std::string targetName) :
    matcher(memberExpr(hasAncestor(cxxMethodDecl(isExpansionInMainFile(), ofClass(hasName(targetName))).bind("fdecl"))).bind("mexpr"))
{
}

StatementMatcher MemberAccessMatcher::getMatcher()
{
    return matcher;
}

