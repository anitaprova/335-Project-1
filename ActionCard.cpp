#include "ActionCard.hpp"

ActionCard::ActionCard()
{
	this->setType(ACTION_CARD);
}

bool ActionCard::isPlayable()
{
	if (this->getDrawn() == 1)
	{
		if (this->getInstruction().substr(0, 3) == "DRAW" && this->getInstruction().substr(7) == "CARD(S)")
		{

			return true;
		}
		else if (this->getInstruction().substr(0, 3) == "PLAY" && this->getInstruction().substr(7) == "CARD(S)")
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
}

void ActionCard::Print() const
{
	std::cout << "Type: " << this->getType() << "Instruction: " << this->getInstruction() << "Card: " << this->getImageData();
}