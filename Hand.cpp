#include "Hand.hpp"

Hand::Hand()
{
}

Hand::~Hand()
{
	cards_.clear();
}

Hand::Hand(const Hand &other)
{
	cards_ = other.cards_;

	// for (int i = 0; i < other.cards_.size(); ++i)
	// {
	// 	cards_[i] = other.cards_[i];
	// }
}

Hand &Hand::operator=(const Hand &other)
{
	if (this != &other)
	{
		cards_ = other.cards_;
	}

	// for (int i = 0; i < other.cards_.size(); ++i)
	// {
	// 	cards_[i] = other.cards_[i];
	// }
	return *this;
}

Hand::Hand(Hand &&other)
{
	// std::swap(cards_, other.cards_);
	cards_ = std::move(other.cards_);
}

Hand &Hand::operator=(Hand &&other)
{
	if (this != &other)
	{
		// std::swap(cards_, other.cards_);
		cards_ = std::move(other.cards_);
	}
	return *this;
}

const std::deque<PointCard> &Hand::getCards() const
{
	return cards_;
}

void Hand::addCard(PointCard &&card)
{
	card.setDrawn(true);
	cards_.push_back(card);

	//cards_.push_back(std::move(card));
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
	if (!this->isEmpty() && cards_[0].isPlayable())
	{
		int points = std::stoi(cards_[0].getInstruction());
		cards_.pop_front();
		return points;
	}
	else
	{
		throw std::out_of_range("Deck is empty");
	}
}