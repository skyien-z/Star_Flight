EXENAME = main
OBJS = main.o Star.o Graph.o

CXX = clang++
CXXFLAGS = $(CS225) -std=c++1y -stdlib=libc++ -c -g -O0 -Wall -Wextra -pedantic
LD = clang++
LDFLAGS = -std=c++1y -stdlib=libc++ -lc++abi -lm

all : $(EXENAME)

output_msg: ; $(CLANG_VERSION_MSG)

$(EXENAME) : output_msg $(OBJS)
	$(LD) $(OBJS) $(LDFLAGS) -o $(EXENAME)

main.o : main.cpp Graph.h Star.h
	$(CXX) $(CXXFLAGS) main.cpp

Star.o : Star.cpp Star.h
	$(CXX) $(CXXFLAGS) Star.cpp

Graph.o : Graph.cpp Graph.h Star.h
	$(CXX) $(CXXFLAGS) Graph.cpp

clean :
	-rm -f *.o $(EXENAME) test
