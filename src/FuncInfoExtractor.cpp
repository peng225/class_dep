#include "../include/FuncInfoExtractor.h"


std::string FuncInfoExtractor::extractFuncName(const clang::CXXMethodDecl &node)
{
    std::string result;

    auto returnType = node.getReturnType().getAsString();
    auto params = node.parameters();
    auto name = node.getNameAsString();

    result += returnType + " ";
    result += name;
    result +="(";
    for(auto itr = node.param_begin(); itr != node.param_end(); itr++) {
        result += ((*itr)->getType()).getAsString() + ", ";
    }
    if(result.back() == ' ') {
        result.resize(result.size()-2);
    }
    result += ")";

    return result;
}

std::string FuncInfoExtractor::getClassName(const clang::CXXMethodDecl &node)
{
    return node.getParent()->getNameAsString();
}

