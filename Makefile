CXX = g++
CXXFLAGS = -std=c++11 -O2 -Wall

code: main.cpp src.hpp
	$(CXX) $(CXXFLAGS) main.cpp -o code

clean:
	rm -f code *.o
