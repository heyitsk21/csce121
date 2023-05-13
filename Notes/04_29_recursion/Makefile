notes: clean
	g++ -std=c++17 -g -Wall -Wextra -Weffc++ -pedantic-errors -fsanitize=address,undefined -o notes notes.cpp && ./notes

interactive: clean
	g++ -std=c++17 -g -Wall -Wextra -Weffc++ -pedantic-errors -fsanitize=address,undefined -o interactive ica.cpp interactive.cpp  && ./interactive

my_interactive: clean
	g++ -std=c++17 -g -Wall -Wextra -Weffc++ -pedantic-errors -fsanitize=address,undefined -o interactive my_ica.cpp interactive.cpp  && ./interactive

test: clean
	g++ -std=c++17 -g -Wall -Wextra -Weffc++ -pedantic-errors -fsanitize=address,undefined -o test tests.cpp ica.cpp  && ./test

my_test: clean
	g++ -std=c++17 -g -Wall -Wextra -Weffc++ -pedantic-errors -fsanitize=address,undefined -o test tests.cpp my_ica.cpp  && ./test

coverage: clean
	g++ -std=c++17 -g --coverage -o coverage ica.cpp tests.cpp  && ./coverage && gcov -mr ica.cpp

my_coverage: clean
	g++ -std=c++17 -g --coverage -o coverage my_ica.cpp tests.cpp  && ./coverage && gcov -mr my_ica.cpp

run: clean notes
	./notes

#unsanitized: clean
#	g++ -std=c++17 -g -Wall -Wextra -Weffc++ -pedantic-errors -o unsanitized_notes notes.cpp

clean:
	rm -f a.out notes coverage test unsanitized_notes *.gcno *.gcda *.gcov