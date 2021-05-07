#include "../include/MemberAccessFinder.h"
#include "../include/MethodInfoExtractor.h"
#include "../include/FieldInfoExtractor.h"
#include "clang/AST/ASTContext.h"
#include <iostream>
#include <string>

using namespace clang;
using namespace clang::ast_matchers;


MemberAccessFinder::MemberAccessFinder(std::shared_ptr<Target> tgt)
    : tgt(tgt)
{
}

void MemberAccessFinder::run(const MatchFinder::MatchResult &result) {
    ASTContext *context = result.Context;
    MethodInfoExtractor fie;
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
            std::cout << "Member function." << std::endl;
            if(!shouldUseNode(*dynamic_cast<clang::CXXMethodDecl*>(decl))) {
                std::cout << "should not use method." << std::endl;
                return;
            }
            auto funcName = fie.extractFuncName(*dynamic_cast<clang::CXXMethodDecl*>(decl));
            dep += "\"" + funcName + "\"";
        } else {
            std::cout << "Other than member function." << std::endl;
            if(!shouldUseNode(*dynamic_cast<clang::FieldDecl*>(decl))) {
                std::cout << "should not use variable." << std::endl;
                return;
            }
            dep += "\"" + decl->getType().getAsString();
            dep += " ";
            dep += decl->getDeclName().getAsString() + "\"";
        }
    }

    std::cout << "dep = " << dep << std::endl;
}

bool MemberAccessFinder::shouldUseNode(clang::CXXMethodDecl &decl)
{
    MethodInfoExtractor mie;
    bool result = false;
    auto className = mie.getClassName(decl);
    std::cout << "className = " << className << std::endl;
    std::cout << "targetName = \"" << tgt->getName() << "\"" << std::endl;
    auto targetNames = tgt->getNames();
    for(const auto &name : targetNames) {
        if(className == name) {
            result = true;
            break;
        }
    }
    return result;
}

bool MemberAccessFinder::shouldUseNode(clang::FieldDecl &decl)
{
    FieldInfoExtractor fie;
    bool result = false;
    auto className = fie.getClassName(decl);
    std::cout << "className = " << className << std::endl;
    std::cout << "targetName = \"" << tgt->getName() << "\"" << std::endl;
    auto targetNames = tgt->getNames();
    for(const auto &name : targetNames) {
        std::cout << "name = " << name << std::endl;
        if(className == name) {
            result = true;
            break;
        }
    }
    return result;
}

