
#Make test creates a driver to test the question making Function
#and the topics generated
test_gen_topics: questions.cpp questions.hpp topics.cpp topics.hpp answers.cpp answers.hpp
	make clean
	g++ -o test_gen_topics test_gen_topics.cpp questions.cpp questions.hpp topics.cpp topics.hpp answers.cpp answers.hpp

clean:
	rm -f  *o test_gen_topics
