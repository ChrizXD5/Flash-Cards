# Build for Flash-Cards

.PHONY: all
all : flashcards

.PHONY: clean
clean:
	@rm -f Quiz.o clearScreen.o getInput.o Question.o flashcards.o flashcards

flashcards.o: flashcards.cpp
	g++ -c flashcards.cpp

Quiz.o: Quiz.cpp Quiz.hpp
	g++ -c Quiz.cpp

Question.o: Question.cpp Question.hpp
	g++ -c Question.cpp

getInput.o: getInput.cpp getInput.hpp
	g++ -c getInput.cpp

clearScreen.o: clearScreen.cpp clearScreen.hpp
	g++ -c clearScreen.cpp

flashcards: Quiz.o clearScreen.o getInput.o Question.o flashcards.o
	g++ Quiz.o clearScreen.o getInput.o Question.o flashcards.o -o flashcards
