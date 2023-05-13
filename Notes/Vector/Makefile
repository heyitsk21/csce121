CXX = g++
override CXXFLAGS += -std=c++17 -g -Wall -Wextra -Weffc++ -pedantic-errors

main: clean main.cpp tests.cpp vector.hpp
	$(CXX) $(CXXFLAGS) -o main main.cpp tests.cpp

sanitizers: clean main.cpp tests.cpp vector.hpp
	$(CXX) $(CXXFLAGS) -fsanitize=address,undefined -o sanitizers main.cpp tests.cpp

coverage: clean main.cpp tests.cpp vector.hpp
	$(CXX) -std=c++17 -g --coverage -o coverage tests.cpp main.cpp && ./coverage && gcov -mr tests.cpp
	rm -f *.gcno *.gcda

clean:
	rm -f main.o main coverage sanitizers *.gcov *.gcno *.gcov *.gcda