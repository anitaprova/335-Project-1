#pragma once
#include <iostream>
#include <vector>
#include <algorithm>
#include "Card.h"
#include "ActionCard.h"
#include "PointCard.h"

template <class Card>
class Deck
{
public:
	Deck();
	~Deck();
	void addCard(Card item);
	void shuffle();
	Card draw();

private:
	std::vector<Card> *deck;
};