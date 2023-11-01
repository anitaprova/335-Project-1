#include "PointCard.hpp"

PointCard::PointCard()
{
	std::string instruction_ = "0";
	bool drawn_ = false;
	this->setImageData(nullptr);
	this->setType(POINT_CARD);
}

bool PointCard::isPlayable()
{
	if (this->getDrawn() == 1 && std::stoi(this->getInstruction()) >= 0)
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
	}
}
