notes: notes.cpp
	g++ -std=c++17 -g -Wall -Wextra -Weffc++ -pedantic-errors -fsanitize=address,undefined -o notes notes.cpp

#main: main.cpp functions.cpp functions.hpp
#	g++ -std=c++17 -g -Wall -Wextra -Weffc++ -pedantic-errors -fsanitize=address,undefined -o test test.cpp tests.cpp functions.cpp

#test: test.cpp tests.cpp functions.cpp functions.hpp
#	g++ -std=c++17 -g -Wall -Wextra -Weffc++ -pedantic-errors -fsanitize=address,undefined -o test test.cpp tests.cpp functions.cpp

#debug: main.cpp functions.cpp
#	g++ -std=c++17 -g -o debug main.cpp functions.cpp

run: clean notes
	./notes

#unsanitized: clean notes.cpp
#	g++ -std=c++17 -g -Wall -Wextra -Weffc++ -pedantic-errors -o unsanitized_notes notes.cpp

clean:
	rm -f notes unsanitized_notes main test debug