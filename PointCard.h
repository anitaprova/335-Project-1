#pragma once
#include <string>
#include "Card.h"

class PointCard : Card
{
public:
	PointCard();
	PointCard(std::string p, std::string t, std::vector<int> v);
	void play();
};