notes: notes.cpp linkedlist.cpp
	g++ -std=c++17 -g -Wall -Wextra -Weffc++ -pedantic-errors -fsanitize=address,undefined -o notes notes.cpp linkedlist.cpp

starter: notes.cpp linkedlist_starter.cpp
	g++ -std=c++17 -g -Wall -Wextra -Weffc++ -pedantic-errors -o starter notes.cpp linkedlist_starter.cpp

coverage: clean notes.cpp linkedlist.cpp
	g++ -std=c++17 -g --coverage -o coverage notes.cpp linkedlist.cpp && ./coverage && gcov -mr linkedlist.cpp

run: clean notes
	./notes

#unsanitized: clean notes.cpp
#	g++ -std=c++17 -g -Wall -Wextra -Weffc++ -pedantic-errors -o unsanitized_notes notes.cpp

clean:
	rm -f a.out notes coverage starter unsanitized_notes *.gcno *.gcda *.gcov