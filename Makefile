# Makefile

#SRC=sample/sample.cpp
#CLASS=Sample
#SRC=../cnn/src/layer.cpp
#CLASS=PoolingLayer
SRC=../cnn/src/layer.cpp
CLASS=ConvolutionLayer
DSTDIR=/mnt/c/Users/shiny/OneDrive/ドキュメント
#CLASS_DEP_OPT=--match-base
CLASS_DEP_OPT=
FIG_FORMAT = png
TARGET = dep_$(CLASS).$(FIG_FORMAT)
PY=python3

all: $(TARGET)

$(TARGET): dep_$(CLASS).dot
	dot -T $(FIG_FORMAT) -o $@ $^
	cp $@ $(DSTDIR)

dep_$(CLASS).dot: class_dep_out_$(CLASS).txt
	cd misc && $(PY) gen_graph.py ../$^ ../$@

class_dep_out_$(CLASS).txt: stop_cmake.txt
	cd build && ninja && ./class_dep $(CLASS_DEP_OPT) --class-name=$(CLASS) ../$(SRC) --extra-arg='-std=c++17' -- | sort | uniq > ../$@

stop_cmake.txt:
	cd build && cmake -GNinja -DCMAKE_EXPORT_COMPILE_COMMANDS=ON ../src
	touch $@

clean:
	rm -f dep_*.* class_dep_out_*.txt stop_cmake.txt

.PHONY: all clean
