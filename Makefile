OBJECTS = Card.o Deck.o ActionCard.o PointCard.o Hand.o Player.o
CXXFLAGS = -g -o
LDFLAGS =
CXX = g++

main: main.o $(OBJECTS)
	$(CXX) $(CXXFLAGS) main main.o $(OBJECTS)

Card.o: Card.cpp Card.h

Deck.o: Deck.cpp Deck.h Card.h

ActionCard.o: ActionCard.cpp ActionCard.h

PointCard.o: PointCard.cpp PointCard.h

Hand.o: Hand.cpp Hand.h

Player.o: Player.cpp Player.h

