#include "Card.hpp"

Card::Card()
{
	instruction_ = "";
	drawn_ = false;
	bitmap_ = new int[80];
	// bitmap_ = nullptr;
}

Card::~Card()
{
	delete[] bitmap_;
	bitmap_ = nullptr;
	// if (bitmap_ != nullptr)
	// {
	// 	delete[] bitmap_;
	// 	bitmap_ = nullptr;
	// }
}

Card::Card(const Card &rhs)
{
	cardType_ = rhs.cardType_;
	instruction_ = rhs.instruction_;
	drawn_ = rhs.drawn_;

	if (rhs.bitmap_ != nullptr)
	{
		bitmap_ = new int[80];
		for (int i = 0; i < 80; ++i)
		{
			bitmap_[i] = rhs.bitmap_[i];
		}
	}
	else
	{
		bitmap_ = nullptr;
	}
}

Card &Card::operator=(const Card &rhs)
{
	if (this != &rhs)
	{
		cardType_ = rhs.cardType_;
		instruction_ = rhs.instruction_;
		drawn_ = rhs.drawn_;
		//delete[] bitmap_;
		bitmap_ = new int[80];
		for (int i = 0; i < 80; ++i)
		{
			bitmap_[i] = rhs.bitmap_[i];
		}

		// if (rhs.bitmap_ != nullptr)
		// {
		// 	bitmap_ = new int[80];
		// 	for (int i = 0; i < 80; ++i)
		// 	{
		// 		bitmap_[i] = rhs.bitmap_[i];
		// 	}
		// }
		// else
		// {
		// 	bitmap_ = nullptr;
		// }
	}
	return *this;
}

Card::Card(Card &&rhs)
{
	cardType_ = std::move(rhs.cardType_);
	drawn_ = std::move(rhs.drawn_);
	instruction_ = std::move(rhs.instruction_);
	bitmap_ = std::move(rhs.bitmap_);

	// cardType_ = rhs.cardType_;
	// instruction_ = rhs.instruction_;
	// rhs.instruction_ = "";
	// drawn_ = rhs.drawn_;
	// rhs.drawn_ = false;
	// std::swap(bitmap_, rhs.bitmap_);
	// rhs.bitmap_ = nullptr;
}

Card &Card::operator=(Card &&rhs)
{
	if (this != &rhs)
	{
		cardType_ = std::move(rhs.cardType_);
		instruction_ = std::move(rhs.instruction_);
		drawn_ = std::move(rhs.drawn_);
		bitmap_ = std::move(rhs.bitmap_);
		// for(int i = 0; i < 80; i++)
		// {
		// 	std::swap(bitmap_[i], rhs.bitmap_[i]);
		// }

		// std::swap(cardType_, rhs.cardType_);
		// std::swap(instruction_, rhs.instruction_);
		// std::swap(drawn_, rhs.drawn_);
		// std::swap(bitmap_, rhs.bitmap_);
	}
	return *this;
}

std::string Card::getType() const
{
	if (cardType_ == ACTION_CARD)
	{
		return "ACTION_CARD";
	}
	else
	{
		return "POINT_CARD";
	}
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
	if (data != nullptr)
	{
		bitmap_ = new int[80];
		for (int i = 0; i < 80; i++)
		{
			bitmap_[i] = data[i];
		}
	}
	else
	{
		bitmap_ = nullptr;
	}

	// bitmap_ = data;
}

bool Card::getDrawn() const
{
	return drawn_;
}

void Card::setDrawn(const bool &drawn)
{
	drawn_ = drawn;
}
