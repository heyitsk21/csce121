notes: clean
	g++ -std=c++17 -g -Wall -Wextra -Weffc++ -pedantic-errors -fsanitize=address,undefined -o notes notes.cpp functions.cpp && ./notes

test: clean
	g++ -std=c++17 -g -Wall -Wextra -Weffc++ -pedantic-errors -fsanitize=address,undefined -o test tests.cpp functions.cpp && ./test

coverage: clean
	g++ -std=c++17 -g --coverage -o coverage notes.cpp functions.cpp && ./coverage && gcov -mr functions.cpp

run: clean notes
	./notes

#unsanitized: clean
#	g++ -std=c++17 -g -Wall -Wextra -Weffc++ -pedantic-errors -o unsanitized_notes notes.cpp

clean:
	rm -f a.out notes coverage unsanitized_notes *.gcno *.gcda *.gcov