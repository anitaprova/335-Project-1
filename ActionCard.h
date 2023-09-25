#pragma once
#include "Card.h"

class ActionCard : public Card
{
public:
	ActionCard();
	ActionCard(std::string p, std::string t, std::vector<int> v);
	void play();
};