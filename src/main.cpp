#include "../include/MethodFinder.h"
#include "../include/MemberAccessFinder.h"
#include "../include/BasesFinder.h"
#include "../include/MethodMatcher.h"
#include "../include/MemberAccessMatcher.h"
#include "../include/BasesMatcher.h"
#include "../include/Target.h"
// Declares clang::SyntaxOnlyAction.
#include "clang/Frontend/FrontendActions.h"
#include "clang/Tooling/CommonOptionsParser.h"
#include "clang/Tooling/Tooling.h"
#include "clang/ASTMatchers/ASTMatchers.h"
// Declares llvm::cl::extrahelp.
#include "llvm/Support/CommandLine.h"

#include <memory>
#include <iostream>

using namespace clang;
using namespace clang::tooling;
using namespace clang::ast_matchers;
using namespace llvm;

// Apply a custom category to all command-line options so that they are the
// only ones displayed.
static cl::OptionCategory classDepCategory("class_dep options");

// CommonOptionsParser declares HelpMessage with a description of the common
// command-line options related to the compilation database and input files.
// It's nice to have this help message in all tools.
static cl::extrahelp CommonHelp(CommonOptionsParser::HelpMessage);

// A help message for this specific tool can be added afterwards.
static cl::extrahelp MoreHelp("\nMore help text...\n");

static cl::opt<std::string> classNameOption("class-name", cl::cat(classDepCategory)); 
static cl::opt<bool> matchBaseOption("match-base", cl::cat(classDepCategory));


int main(int argc, const char **argv)
{
    auto expectedParser = CommonOptionsParser::create(argc, argv, classDepCategory,
            llvm::cl::OneOrMore, nullptr);
    if (!expectedParser) {
        // Fail gracefully for unsupported options.
        llvm::errs() << expectedParser.takeError();
        return 1;
    }
    CommonOptionsParser& optionsParser = expectedParser.get();
    ClangTool tool(optionsParser.getCompilations(),
                   optionsParser.getSourcePathList());

    auto tgt = std::make_shared<Target>(classNameOption.getValue());
    auto matchBase = matchBaseOption.getValue();

    if(matchBase) {
        // List up all base classes.
        MatchFinder finder;
        BasesFinder basesFinder(tgt);

        BasesMatcher basesMatcher(tgt->getName());
        finder.addMatcher(basesMatcher.getMatcher(), &basesFinder);

        if(int ret = tool.run(newFrontendActionFactory(&finder).get()) != 0) {
            std::cerr << "Matcher failed." << ret << std::endl;
            return ret;
        }
    }

    MatchFinder finder;
    auto targetNames = tgt->getNames();
    std::cout << "target num = " << targetNames.size() << std::endl;
    std::vector<MethodFinder> methodFinders(targetNames.size());
    std::vector<MemberAccessFinder> memberAccessFinders;
    for(const auto &name : targetNames) {
        memberAccessFinders.emplace_back(MemberAccessFinder(tgt));
    }
    for(int i = 0; i < static_cast<int>(targetNames.size()); i++) {
        std::cout << "input name = " << targetNames.at(i) << std::endl;

        MethodMatcher methodMatcher(targetNames.at(i));
        MemberAccessMatcher memberAccessMatcher(targetNames.at(i));
        finder.addMatcher(methodMatcher.getMatcher(), &methodFinders.at(i));
        finder.addMatcher(memberAccessMatcher.getMatcher(), &memberAccessFinders.at(i));
    }

    return tool.run(newFrontendActionFactory(&finder).get());
}

