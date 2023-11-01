#pragma once
#include "Hand.hpp"

Hand::Hand(){

}

Hand::~Hand(){
	
}

Hand::Hand(const Hand &other)
{
	cards_ = other.getCards();
}

Hand &Hand::operator=(const Hand &other)
{
	Hand copy = other;
	std::swap(*this, copy);
	return *this;
}

Hand::Hand(Hand &&other)
{
	cards_ = std::move(other.getCards());
}

Hand &Hand::operator=(Hand &&other)
{
	std::swap(*this, other);
	return *this;
}

const std::deque<PointCard> &Hand::getCards() const
{
	return cards_;
}

void Hand::addCard(PointCard &&card)
{
	cards_.push_front(card);
}

bool Hand::isEmpty() const
{
	return cards_.empty();
}

void Hand::Reverse()
{
	for (int i = 0; i < cards_.size() / 2; i++)
	{
		std::swap(cards_[i], cards_[cards_.size() - 1 - i]);
	}
}

int Hand::PlayCard()
{
	if (!this->isEmpty() && !cards_[0].isPlayable())
	{
		int points = stoi(cards_[0].getInstruction());
		cards_.pop_front();
		return points;
	}
	else
	{
		throw std::out_of_range("empty");
	}
}