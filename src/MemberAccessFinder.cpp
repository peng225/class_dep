#include "../include/MemberAccessFinder.h"
#include "../include/FuncInfoExtractor.h"
#include "clang/AST/ASTContext.h"
#include <iostream>
#include <string>

using namespace clang;
using namespace clang::ast_matchers;


MemberAccessFinder::MemberAccessFinder(std::shared_ptr<Target> tgt) : tgt(tgt)
{
}

void MemberAccessFinder::run(const MatchFinder::MatchResult &result) {
    ASTContext *context = result.Context;
    FuncInfoExtractor fie;
    std::string dep;
    if(auto *node = result.Nodes.getNodeAs<clang::CXXMethodDecl>("fdecl")) {
        dep += "\"" + fie.extractFuncName(*node) + "\"";
    }

    dep += " -> ";

    if(auto *node = result.Nodes.getNodeAs<clang::MemberExpr>("mexpr")) {
        // node->dump();
        auto decl = node->getMemberDecl();
        auto cls = node->Classify(*context);
        if(cls.getKind() == clang::Expr::Classification::Kinds::CL_MemberFunction) {
            //std::cout << "Member function." << std::endl;
            //std::cout << "Target: " << tgt->getName() << std::endl;
            auto className = fie.getClassName(*dynamic_cast<clang::CXXMethodDecl*>(decl));
            if(className != tgt->getName()) {
                return;
            }
            auto funcName = fie.extractFuncName(*dynamic_cast<clang::CXXMethodDecl*>(decl));
            dep += "\"" + funcName + "\"";
        } else {
            //std::cout << "Other than member function." << std::endl;
            dep += "\"" + decl->getType().getAsString();
            dep += " ";
            dep += decl->getDeclName().getAsString() + "\"";
        }
    }

    std::cout << "dep = " << dep << std::endl;
}

