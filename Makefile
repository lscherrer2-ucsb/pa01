CXX=g++ 
CXXFLAGS = -g --std=c++20 -Wall

all: game game_set

game_set: card.o main_set.o game_set.o
	${CXX} ${CXXFLAGS} $^ -o $@

game: card.o card_list.o main.o game.o
	${CXX} ${CXXFLAGS} $^ -o $@

tests: card.o card_list.o tests.o
	${CXX} ${CXXFLAGS} card.o card_list.o tests.o -o tests
	./tests

main_set.o: main_set.cpp
	${CXX} ${CXXFLAGS} main_set.cpp -c

main.o: main.cpp
	${CXX} ${CXXFLAGS} main.cpp -c

tests.o: tests.cpp
	${CXX} ${CXXFLAGS} tests.cpp -c

card_list.o: card_list.cpp card_list.h
	${CXX} ${CXXFLAGS} card_list.cpp -c

card.o: card.cpp card.h
	${CXX} ${CXXFLAGS} card.cpp -c

game.o: game.cpp game.h
	${CXX} ${CXXFLAGS} $< -o $@

game_set.o: game_set.cpp game_set.h
	${CXX} ${CXXFLAGS} $< -o $@


clean:
	rm game_set game *.o
