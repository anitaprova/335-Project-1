#include "Card.hpp"

Card::Card()
{
	std::string instruction_ = "";
	bool drawn_ = false;
}

Card::~Card()
{
	delete bitmap_;
}

// copy
Card::Card(const Card &rhs)
{
	cardType_ = rhs.cardType_;
	instruction_ = rhs.instruction_;
	drawn_ = rhs.drawn_;
	bitmap_ = rhs.bitmap_;
}

Card &Card::operator=(const Card &rhs)
{
	if (this != &rhs)
	{
		cardType_ = rhs.cardType_;
		instruction_ = rhs.instruction_;
		drawn_ = rhs.drawn_;
		bitmap_ = rhs.bitmap_;
	}
	return *this;
}

Card::Card(Card &&rhs)
{
	cardType_ = rhs.cardType_;
	instruction_ = rhs.instruction_;
	drawn_ = rhs.drawn_;
	bitmap_ = rhs.bitmap_;
}

// move
Card &Card::operator=(Card &&rhs)
{
	if (this != &rhs)
	{
		cardType_ = rhs.cardType_;
		instruction_ = rhs.instruction_;
		drawn_ = rhs.drawn_;
		bitmap_ = rhs.bitmap_;
	}
	return *this;
}

std::string Card::getType() const
{
	return cardType_ + "";
}

void Card::setType(const CardType &type)
{
	cardType_ = type;
}

const std::string &Card::getInstruction() const
{
	return instruction_;
}

void Card::setInstruction(const std::string &instruction)
{
	instruction_ = instruction;
}

const int *Card::getImageData() const
{
	return bitmap_;
}

void Card::setImageData(int *data)
{
	bitmap_ = data;
}

bool Card::getDrawn() const
{
	return drawn_;
}

void Card::setDrawn(const bool &drawn)
{
	drawn_ = drawn;
}
