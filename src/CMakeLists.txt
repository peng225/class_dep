cmake_minimum_required(VERSION 3.16.3)

project(class_dep)

# LLVMConfig.cmake を読み込む。
find_package(LLVM REQUIRED CONFIG)
# ClangConfig.cmake を読み込む。
find_package(Clang REQUIRED CONFIG)

# LLVM_LINK_LLVM_DYLIB は LLVMConfig.cmake の中で ON に設定されている。
# CLANG_LINK_CLANG_DYLIB も ON に設定する。
set(CLANG_LINK_CLANG_DYLIB ${LLVM_LINK_LLVM_DYLIB})

# add_clang_executable の中で使用される add_llvm_executable のために AddLLVM.cmake を読み込む。
list(APPEND CMAKE_MODULE_PATH ${LLVM_DIR})
include(AddLLVM)

list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/../cmake/modules")
include(AddClang)

include_directories(${LLVM_INCLUDE_DIRS})
include_directories(${CLANG_INCLUDE_DIRS})

# https://github.com/llvm/llvm-project/blob/llvmorg-10.0.0/clang/cmake/modules/AddClang.cmake#L139
add_clang_executable(
class_dep
main.cpp
MethodFinder.cpp
MemberAccessFinder.cpp
BasesFinder.cpp
MethodMatcher.cpp
MemberAccessMatcher.cpp
BasesMatcher.cpp
MethodInfoExtractor.cpp
FieldInfoExtractor.cpp
Target.cpp)

# https://github.com/llvm/llvm-project/blob/llvmorg-10.0.0/clang/cmake/modules/AddClang.cmake#L181
# CLANG_LINK_CLANG_DYLIB があると動的リンク (clang-cpp とリンク) になる。
clang_target_link_libraries(class_dep PRIVATE clangFrontend clangTooling)
