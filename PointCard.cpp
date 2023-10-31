#include "PointCard.hpp"

PointCard::PointCard()
{
	this->setType(POINT_CARD);
}

bool PointCard::isPlayable()
{
	if (this->getDrawn() == 1 && isdigit(std::stoi(this->getInstruction())))
	{
		return true;
	}
	return false;
}

void PointCard::Print() const
{
	std::cout << "Type: " << this->getType() << "\nPoints: " << this->getInstruction() << "\nCard:\n";
	if (this->getImageData()[0] == 0)
	{
		std::cout << "No image data\n";
	}
	else
	{
		for (int i = 0; i < 80; i++)
		{
			std::cout << this->getImageData()[i] << "\n";
		}
	}
}
