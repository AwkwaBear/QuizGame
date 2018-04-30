display_test: main.cpp intro.cpp intro.hpp
	g++ -c intro.hpp intro.cpp main.cpp
	g++ main.o intro.o -o display_test -lsfml-graphics -lsfml-window -lsfml-system

button_test:
	g++ -c buttons/main.cpp buttons/include/button.hpp buttons/src/button.cpp
	g++ main.o button.o -o button_test -lsfml-graphics -lsfml-window -lsfml-system
