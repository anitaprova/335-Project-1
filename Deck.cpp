#include "Deck.h"

template <typename T> Deck<T>::Deck()
{

}

template <typename T> Deck<T>::~Deck()
{

}

template <typename T> void Deck<T>::addCard(T item)
{
	deck.push_back(item);
}

// uses c++ shuffle 
template <typename T> void Deck<T>::shuffle()
{
	std::shuffle(deck.begin(), deck.end());
}

template <typename T> T Deck<T>::draw()
{
	if(!deck.empty())
	{
		T tempCard = deck.back();
		deck.pop_back();
		return tempCard; 
	}
}