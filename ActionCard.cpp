#include "ActionCard.hpp"

ActionCard::ActionCard()
{
	setInstruction("");
	bool drawn_ = false;
	this->setImageData(nullptr);
	this->setType(ACTION_CARD);
}

bool ActionCard::isPlayable()
{
	if (this->getDrawn() == 1)
	{
		std::regex draw("^DRAW [0-9] CARD\\(S\\)");
		std::regex play("^PLAY [0-9] CARD\\(S\\)");
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
		for (int i = 0; i < 80; i++)
		{
			std::cout << this->getImageData()[i] << " ";
		}
		std::cout << "\n";
	}
}