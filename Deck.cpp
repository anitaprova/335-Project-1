#include "Deck.h"

template <class Card>
Deck<Card>::Deck()
{
}

template <class Card>
Deck<Card>::~Deck()
{
	delete[] deck;
}

template <class Card>
void Deck<Card>::addCard(Card item)
{
	deck.push_back(item);
}

// uses c++ shuffle
template <class Card>
void Deck<Card>::shuffle()
{
	std::shuffle(deck.begin(), deck.end());
}

template <class Card>
Card Deck<Card>::draw()
{
	if (!deck.empty())
	{
		Card tempCard = deck.back();
		deck.pop_back();
		return tempCard;
	}
}