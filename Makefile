.PHONY: all
CXXFLAGS=-std=c++11 -pedantic -Wall -Wextra -g -O0

all: $(patsubst %.cpp,%,$(wildcard *.cpp))

%: %.cpp
	$(CXX) -o $@ $(CPPFLAGS) $(CXXFLAGS) $(LDFLAGS) $^
