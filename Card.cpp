#include "Card.hpp"
/**
 * Default Constructor
 * @post: Creates the Card object
 */
Card::Card()
{
	instruction_ = "";
	drawn_ = false;
	bitmap_ = nullptr;
}

/**
 * Destructor
 * @post: Destroy the Card object
 */
Card::~Card()
{
	delete[] bitmap_;
	bitmap_ = nullptr;
}

/**
 * Copy Constructor
 * @post: Construct a new Card object
 * @param: const reference to a Card object
 */
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

/**
 * Copy Assignment Operator
 * @param const reference to a Card object
 * @return this Card object
 */
Card &Card::operator=(const Card &rhs)
{
	if (this != &rhs)
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
	return *this;
}

/**
 * Move Constructor
 * @param: rvalue reference to a Card object
 */
Card::Card(Card &&rhs)
{
	cardType_ = std::move(rhs.cardType_);
	drawn_ = std::move(rhs.drawn_);
	instruction_ = std::move(rhs.instruction_);
	bitmap_ = std::move(rhs.bitmap_);
	rhs.bitmap_ = nullptr;
}

/**
 * Move assignment operator
 * @param: rvalue reference to a Card object
 * @return this card object
 */
Card &Card::operator=(Card &&rhs)
{
	if (this != &rhs)
	{
		cardType_ = std::move(rhs.cardType_);
		instruction_ = std::move(rhs.instruction_);
		drawn_ = std::move(rhs.drawn_);
		bitmap_ = std::move(rhs.bitmap_);
		rhs.bitmap_ = nullptr;
	}
	return *this;
}

/**
 * @return the string representation of the card type
 */
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

/**
 * @post: set the card type
 * @param const reference to a CardType object
 */
void Card::setType(const CardType &type)
{
	cardType_ = type;
}

/**
 * @return the string representation of the card instruction
 */
const std::string &Card::getInstruction() const
{
	return instruction_;
}

/**
 * @post: set the card instruction
 * @param: const reference to an instruction
 */
void Card::setInstruction(const std::string &instruction)
{
	instruction_ = instruction;
}

/**
 * @return the image data
 */
const int *Card::getImageData() const
{
	return bitmap_;
}

/**
 * @post: Set the image data
 * @param pointer to an array of integers
 */
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
}

/**
 * @return the drawn status of the card
 */
bool Card::getDrawn() const
{
	return drawn_;
}

/**
 * @post: set the drawn status of the card
 *
 * @param: const reference to a boolean
 */
void Card::setDrawn(const bool &drawn)
{
	drawn_ = drawn;
}
