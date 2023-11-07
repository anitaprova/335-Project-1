#include "ActionCard.hpp"

/**
 * @post: Construct a new Action Card object
 */
ActionCard::ActionCard()
{
	this->setInstruction("");
	this->setDrawn(false);
	this->setImageData(nullptr);
	this->setType(ACTION_CARD);
}

/**
 * @return true if the card is playable, false otherwise
 * For a card to be playable, it has to be drawn and the instruction has to be valid
 * Valid instructions:
 * DRAW x CARD(S) : assume x is a positive integer
 * PLAY x CARD(S) : assume x is a positive integer
 * REVERSE HAND : reverse the order of the cards in the hand
 * SWAP HAND WITH OPPONENT : swap the hand with the opponent
 */
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

/**
 * @post: Print the ActionCard in the following format:
 * Type: [CardType]
 * Instruction: [Instruction]
 * Card:
 * [ImageData]
 *
 * Note: For [ImageData]: If there is no image data, print "No image data" instead
 */
void ActionCard::Print() const
{
	std::cout << "Type: " << this->getType() << "\nInstruction: " << this->getInstruction() << "\nCard:\n";
	if (this->getImageData() == nullptr)
	{
		std::cout << "No image data\n";
	}
	else
	{
		std::cout << this->getImageData() << "\n";
	}
}