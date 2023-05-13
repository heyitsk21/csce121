CXX = g++
override CXXFLAGS += -g -std=c++17 -Wall -Wextra -Weffc++ -pedantic-errors

main: clean functions.cpp tests.cpp main.cpp
	$(CXX) $(CXXFLAGS) functions.cpp tests.cpp main.cpp -o main

coverage: clean functions.cpp tests.cpp main.cpp
	$(CXX) -g -std=c++17 --coverage functions.cpp tests.cpp main.cpp -o coverage && ./coverage && gcov -mr functions.cpp

memcheck: clean functions.cpp tests.cpp main.cpp
	$(CXX) $(CXXFLAGS) -fsanitize=address,undefined functions.cpp tests.cpp main.cpp -o memcheck && ./memcheck

clean:
	rm -f main *.gcda *.gcno *.gcov coverage memcheck