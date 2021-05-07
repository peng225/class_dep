#!/usr/bin/python3

import sys

def writeHeader(outputFile):
    with open("headerTemplate.txt", 'r') as htFile:
        text = htFile.read()
        outputFile.write(text)

def writeFuncNames(outputFile, methods):
    outputFile.write("  // node definition\n")
    for method in methods:
        outputFile.write("  " + method + " [shape = box];\n")
    print("\n")

def writeDependencies(outputFile, dependencies):
    outputFile.write("  // edge definition\n")
    for dep in dependencies:
        spdep = dep.split(" -> ")
        outputFile.write("  " + spdep[0] + " -> " + spdep[1] + ";\n")

def main():
    if len(sys.argv) != 3:
        print("usage: " + sys.argv[0] + " input output")
        sys.exit()

    inputFileName = sys.argv[1]
    outputFileName = sys.argv[2]
    with open(inputFileName, 'r') as inputFile:
        lines = inputFile.read().splitlines()

    methodMark = "method = "
    depMark = "dep = "

    with open(outputFileName, 'w') as outputFile:
        writeHeader(outputFile)
        methods = []
        dependencies = []

        for line in lines:
            if line.startswith(methodMark):
                methods.append(line.split(methodMark)[1])
            elif line.startswith(depMark):
                dependencies.append(line.split(depMark)[1])

        writeFuncNames(outputFile, methods)
        writeDependencies(outputFile, dependencies)
        outputFile.write("}\n")


if __name__ == "__main__":
    main()

