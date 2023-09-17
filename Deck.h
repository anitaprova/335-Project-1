#pragma once
#include <iostream>
#include <vector>
#include <algorithm>
#include "ActionCard.h"
#include "PointCard.h"

template <typename T>
class Deck
{
public:
	Deck();
	~Deck();
	void addCard(T item);
	void shuffle();
	T draw();
private:
	std::vector<T> deck;
};