#include "ActionCard.hpp"

ActionCard::ActionCard()
{
	this->setType(ACTION_CARD);
}

bool ActionCard::isPlayable()
{
	if (this->getDrawn() == 1)
	{
		if (this->getInstruction().substr(0, 4) == "DRAW" && this->getInstruction().substr(7) == "CARD(S)")
		{
			return true;
		}
		else if (this->getInstruction().substr(0, 4) == "PLAY" && this->getInstruction().substr(7) == "CARD(S)")
		{
			return true;
		}
		else if (this->getInstruction() == "REVERSE HAND" || this->getInstruction() == "SWAP HAND WITH OPPONENT")
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	else
	{
		return false;
	}
}

void ActionCard::Print() const
{
	std::cout << "Type: " << this->getType() << "\nInstruction: " << this->getInstruction() << "\nCard:\n";
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