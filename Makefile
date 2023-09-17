OBJECTS = Card.o Deck.o ActionCard.o PointCard.o Hand.o Player.o
CXXFLAGS = -g -c -Wall -o
LDFLAGS =
CXX = g++

main: main.o $(OBJECTS)
	g++ -g -Wall -o main main.o $(OBJECTS)

main.o: main.cpp

Card.o: Card.cpp Card.h

Deck.o: Deck.cpp Deck.h Card.h ActionCard.h PointCard.h

ActionCard.o: ActionCard.cpp ActionCard.h

PointCard.o: PointCard.cpp PointCard.h

Hand.o: Hand.cpp Hand.h

Player.o: Player.cpp Player.h

clean: 
	rm main main.o $(OBJECTS)

