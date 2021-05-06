EXENAME = main
OBJS = main.o Star.o StarInitializer.o AStar.o BFS.o Visualizer.o PNG.o HSLAPixel.o lodepng.o

CXX = clang++
CXXFLAGS = $(CS225) -std=c++1y -stdlib=libc++ -c -g -O0 -Wall -Wextra -pedantic
LD = clang++
LDFLAGS = -std=c++1y -stdlib=libc++ -lc++abi -lm

# Custom Clang version enforcement logic:
ccred=$(shell echo -e "\033[0;31m")
ccyellow=$(shell echo -e "\033[0;33m")
ccend=$(shell echo -e "\033[0m")

IS_EWS=$(shell hostname | grep "ews.illinois.edu") 
IS_CORRECT_CLANG=$(shell clang -v 2>&1 | grep "version 6")
ifneq ($(strip $(IS_EWS)),)
ifeq ($(strip $(IS_CORRECT_CLANG)),)
CLANG_VERSION_MSG = $(error $(ccred) On EWS, please run 'module load llvm/6.0.1' first when running CS225 assignments. $(ccend))
endif
else
ifneq ($(strip $(SKIP_EWS_CHECK)),True)
CLANG_VERSION_MSG = $(warning $(ccyellow) Looks like you are not on EWS. Be sure to test on EWS before the deadline. $(ccend))
endif
endif

.PHONY: all test clean output_msg

all : $(EXENAME)

output_msg: ; $(CLANG_VERSION_MSG)

$(EXENAME) : output_msg $(OBJS)
	$(LD) $(OBJS) $(LDFLAGS) -o $(EXENAME)

main.o : main.cpp StarInitializer.h Star.h BFS.h Visualizer.h cs225/HSLAPixel.h cs225/PNG.h cs225/lodepng/lodepng.h
	$(CXX) $(CXXFLAGS) main.cpp

Star.o : Star.cpp Star.h
	$(CXX) $(CXXFLAGS) Star.cpp

StarInitializer.o : StarInitializer.cpp StarInitializer.h Star.h
	$(CXX) $(CXXFLAGS) StarInitializer.cpp

Visualizer.o : Visualizer.cpp Visualizer.h cs225/PNG.h cs225/HSLAPixel.h
	$(CXX) $(CXXFLAGS) Visualizer.cpp

AStar.o: AStar.cpp AStar.h Star.h
	$(CXX) $(CXXFLAGS) AStar.cpp

BFS.o: BFS.cpp BFS.h Star.h
	$(CXX) $(CXXFLAGS) BFS.cpp

test: output_msg catchmain.o StarTest.o StarInitializerTest.o AStarTest.o BFSTest.o Star.o StarInitializer.o AStar.o BFS.o Visualizer.o VisualizerTest.o PNG.o lodepng.o HSLAPixel.o
	$(LD) catchmain.o StarTest.o StarInitializerTest.o AStarTest.o BFSTest.o Star.o StarInitializer.o AStar.o BFS.o VisualizerTest.o Visualizer.o PNG.o lodepng.o HSLAPixel.o $(LDFLAGS) -o test

catchmain.o : cs225/catch/catchmain.cpp cs225/catch/catch.hpp
	$(CXX) $(CXXFLAGS) cs225/catch/catchmain.cpp

StarTest.o: tests/StarTest.cpp cs225/catch/catch.hpp Star.cpp
	$(CXX) $(CXXFLAGS) tests/StarTest.cpp

StarInitializerTest.o: tests/StarInitializerTest.cpp cs225/catch/catch.hpp Star.cpp StarInitializer.cpp
	$(CXX) $(CXXFLAGS) tests/StarInitializerTest.cpp

AStarTest.o: tests/AStarTest.cpp cs225/catch/catch.hpp AStar.cpp Star.cpp
	$(CXX) $(CXXFLAGS) tests/AStarTest.cpp

BFSTest.o: tests/BFSTest.cpp cs225/catch/catch.hpp BFS.cpp StarInitializer.cpp 
	$(CXX) $(CXXFLAGS) tests/BFSTest.cpp

VisualizerTest.o: tests/VisualizerTest.cpp cs225/catch/catch.hpp Visualizer.cpp StarInitializer.cpp cs225/PNG.cpp cs225/HSLAPixel.cpp cs225/lodepng/lodepng.cpp
	$(CXX) $(CXXFLAGS) tests/VisualizerTest.cpp

PNG.o : cs225/PNG.cpp cs225/PNG.h cs225/HSLAPixel.h cs225/lodepng/lodepng.h
	$(CXX) $(CXXFLAGS) cs225/PNG.cpp

HSLAPixel.o : cs225/HSLAPixel.cpp cs225/HSLAPixel.h
	$(CXX) $(CXXFLAGS) cs225/HSLAPixel.cpp

lodepng.o : cs225/lodepng/lodepng.cpp cs225/lodepng/lodepng.h
	$(CXX) $(CXXFLAGS) cs225/lodepng/lodepng.cpp

clean :
	-rm -f *.o *.d $(EXENAME) test
