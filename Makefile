OBJECTS = Card.o Deck.o ActionCard.o PointCard.o Hand.o Player.o
CXXFLAGS = -g -c -o
LDFLAGS =
CXX = g++

main: main.o $(OBJECTS)
	g++ -g -o main main.o $(OBJECTS)

main.o: main.cpp

Card.o: Card.cpp Card.hpp

Deck.o: Deck.hpp

ActionCard.o: ActionCard.cpp ActionCard.hpp

PointCard.o: PointCard.cpp PointCard.hpp

Hand.o: Hand.cpp Hand.hpp

Player.o: Player.cpp Player.hpp

clean: 
	rm main main.o $(OBJECTS)

