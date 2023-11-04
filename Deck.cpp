#include <vector>
#include <algorithm>
#include "Deck.hpp"

template <typename CardType>
Deck<CardType>::Deck()
{
	cards_ = std::vector<CardType>();
}

template <typename CardType>
Deck<CardType>::~Deck()
{
	cards_.clear();
}

template <typename CardType>
void Deck<CardType>::AddCard(const CardType &card)
{
	cards_.push_back(card);
}

template <typename CardType>
CardType &&Deck<CardType>::Draw()
{
	if (!cards_.empty())
	{
		CardType &&c = std::move(cards_.back());
		cards_.pop_back();
		return std::move(c);
	}
}

template <typename CardType>
bool Deck<CardType>::IsEmpty() const
{
	return cards_.empty();
}

template <typename CardType>
void Deck<CardType>::Shuffle()
{
	std::mt19937 g(2028358904);
	std::shuffle(cards_.begin(), cards_.end(), g);
}

template <typename CardType>
int Deck<CardType>::getSize() const
{
	return cards_.size();
}

template <typename CardType>
std::vector<CardType> Deck<CardType>::getDeck() const
{
	return cards_;
}