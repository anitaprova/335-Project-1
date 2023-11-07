#include "PointCard.hpp"

PointCard::PointCard()
{
	setInstruction("0");
	setDrawn(false);
	this->setImageData(nullptr);
	this->setType(POINT_CARD);
}

bool PointCard::isPlayable()
{
	//this->getDrawn() == 1 && 
	if (std::stoi(this->getInstruction()) >= 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}

void PointCard::Print() const
{
	std::cout << "Type: " << this->getType() << "\nPoints: " << this->getInstruction() << "\nCard:\n";
	if (this->getImageData() == nullptr)
	{
		std::cout << "No image data\n";
	}
	else
	{
		 for (int i = 0; i < 80; i++)
		 {
		 	std::cout << this->getImageData()[i] << " ";
		 }
		 std::cout << "\n";
		//std::cout << this->getImageData() << "\n";
	}
}
