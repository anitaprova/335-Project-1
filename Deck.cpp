#include <vector>
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
	if (!IsEmpty())
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
	std::random_device r;
	std::mt19937 random_gen(r());
	std::shuffle(cards_.begin(), cards_.end(), random_gen);
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