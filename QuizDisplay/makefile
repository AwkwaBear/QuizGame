display_test: main.cpp intro.cpp intro.hpp enter_users.cpp enter_users.hpp enter_names.cpp enter_names.hpp user.cpp user.hpp info.cpp info.hpp
	g++ -c intro.hpp intro.cpp enter_users.cpp enter_users.hpp enter_names.cpp enter_names.hpp user.cpp user.hpp info.cpp info.hpp main.cpp
	g++ main.o intro.o enter_users.o enter_names.o user.o info.o -o display_test -lsfml-graphics -lsfml-window -lsfml-system

button_test:
	g++ -c buttons/main.cpp buttons/include/button.hpp buttons/src/button.cpp
	g++ main.o button.o -o button_test -lsfml-graphics -lsfml-window -lsfml-system
