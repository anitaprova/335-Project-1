#include "PointCard.hpp"

/**
 * @post: Construct a new Point Card object
 */
PointCard::PointCard()
{
	setInstruction("0");
	setDrawn(false);
	this->setImageData(nullptr);
	this->setType(POINT_CARD);
}

/**
 * @return true if the card is playable, false otherwise
 * For a card to be playable, it has to be drawn and the instruction has to be a valid number
 */
bool PointCard::isPlayable()
{
	if (std::stoi(this->getInstruction()) >= 0 && this->getDrawn())
	{
		return true;
	}
	else
	{
		return false;
	}
}

/**
 * @post: Print the Point Card in the following format:
 * Type: [CardType]
 * Points: [Instruction]
 * Card:
 * [ImageData]
 *
 * Note: For [ImageData]: If there is no image data, print "No image data" instead
 */
void PointCard::Print() const
{
	std::cout << "Type: " << this->getType() << std::endl;
	std::cout << "Points: " << this->getInstruction() << std::endl;
	std::cout << "Card: " << std::endl;
	if (this->getImageData() == nullptr)
	{
		std::cout << "No image data" << std::endl;
	}
	else
	{
		for (int i = 0; i < 80; ++i)
		{
			std::cout << this->getImageData()[i] << " ";
		}
		std::cout << std::endl;
	}
}
