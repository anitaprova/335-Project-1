#include "ActionCard.hpp"

ActionCard::ActionCard()
{
	this->setInstruction("");
	this->setDrawn(false);
	this->setImageData(nullptr);
	this->setType(ACTION_CARD);
}

bool ActionCard::isPlayable()
{
	if (this->getDrawn())
	{
		std::regex draw("^DRAW \\d+ CARD\\(S\\)");
		std::regex play("^PLAY \\d+ CARD\\(S\\)");
		if (std::regex_match(this->getInstruction(), draw) || std::regex_match(this->getInstruction(), play) || this->getInstruction() == "REVERSE HAND" || this->getInstruction() == "SWAP HAND WITH OPPONENT")
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
	if (this->getImageData() == nullptr)
	{
		std::cout << "No image data\n";
	}
	else
	{
		// for (int i = 0; i < 80; i++)
		// {
		// 	std::cout << this->getImageData()[i] << " ";
		// }

		std::cout << this->getImageData() << "\n";
	}
}