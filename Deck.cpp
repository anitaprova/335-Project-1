#include "Deck.hpp"

template <class CardType>
Deck<CardType>::Deck()
{
	cards_;
}

template <class CardType>
Deck<CardType>::~Deck()
{
	for (int i = 0; i < cards_.size(); ++i)
	{
		//
	}
}

template <class CardType>
void Deck<CardType>::AddCard(const CardType &card)
{
	cards_.push_back(card);
}

template <class CardType>
CardType &&Deck<CardType>::Draw()
{
	if (!cards_.empty())
	{
		CardType c = cards_.back();
		cards_.pop_back();
		return c;
	}
}

template <class CardType>
bool Deck<CardType>::IsEmpty() const
{
	return cards_.empty();
}

template <class CardType>
void Deck<CardType>::Shuffle()
{
	std::mt19937 random_gen(2028358904);
	std::shuffle(v.begin(), v.end(), random_gen);
}

template <class CardType>
int Deck<CardType>::getSize() const
{
	return cards_.size();
}

template <class CardType>
std::vector<CardType> Deck<CardType>::getDeck() const
{
	return cards_;
}