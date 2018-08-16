quiz: main.cpp intro.cpp intro.hpp enter_users.cpp enter_users.hpp enter_names.cpp enter_names.hpp user.cpp user.hpp info.cpp info.hpp gamescreen.cpp gamescreen.hpp questions.cpp questions.hpp topics.cpp topics.hpp answers.cpp answers.hpp end.cpp end.hpp
	g++ -c intro.hpp intro.cpp enter_users.cpp enter_users.hpp enter_names.cpp enter_names.hpp user.cpp user.hpp info.cpp info.hpp gamescreen.cpp gamescreen.hpp questions.cpp questions.hpp topics.cpp topics.hpp answers.cpp answers.hpp end.cpp end.hpp main.cpp
	g++ main.o intro.o enter_users.o enter_names.o user.o info.o gamescreen.o questions.o topics.o answers.o end.o -o quiz -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio

test_gen_topics: test_gen_topics.cpp answers.cpp answers.hpp questions.cpp questions.hpp topics.cpp topics.hpp
	g++ -c test_gen_topics.cpp answers.cpp answers.hpp questions.cpp questions.hpp topics.cpp topics.hpp
	g++ questions.o topics.o answers.o test_gen_topics.o -o test_gen_topics

button_test:
	g++ -c buttons/main.cpp buttons/include/button.hpp buttons/src/button.cpp
	g++ main.o button.o -o button_test -lsfml-graphics -lsfml-window -lsfml-system

clean:
	rm *.o
	rm *.hpp.gch
	rm test_gen_topics
