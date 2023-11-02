#include "Hand.hpp"

Hand::Hand()
{
	//deck of pointcards?
}

Hand::~Hand()
{
	cards_.clear();
	std::cout << "deconstructor\n";
}

Hand::Hand(const Hand &other)
{
	for (int i = 0; i < other.cards_.size(); ++i)
	{
		cards_[i] = other.cards_[i];
	}
}

Hand &Hand::operator=(const Hand &other)
{
	for (int i = 0; i < other.cards_.size(); ++i)
	{
		cards_[i] = other.cards_[i];
	}
	return *this;
}

Hand::Hand(Hand &&other)
{
	std::swap(cards_, other.cards_);
	//std::move(other.cards_);
}

Hand &Hand::operator=(Hand &&other)
{
	if (this != &other)
	{
		std::swap(cards_, other.cards_);
		//cards_ = std::move(other.cards_);
	}
	return *this;
}

const std::deque<PointCard> &Hand::getCards() const
{
	return cards_;
}

void Hand::addCard(PointCard &&card)
{
	cards_.push_back(card);
}

bool Hand::isEmpty() const
{
	return cards_.empty();
}

void Hand::Reverse()
{
	for (int i = 0; i < cards_.size() / 2; i++)
	{
		PointCard &&p = std::move(cards_[i]);
		cards_[i] = std::move(cards_[cards_.size() - 1 - i]);
		cards_[cards_.size() - 1 - i] = std::move(p);
	}
}

int Hand::PlayCard()
{
	if (!this->isEmpty() && cards_[0].isPlayable())
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