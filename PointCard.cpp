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
	std::cout << "Type: " << this->getType() << "Points: " << this->getInstruction() << "Card: " << this->getImageData();
}
