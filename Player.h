#pragma once
#include "Hand.h"

class Player
{
public:
	Player();

	int get_score();

private:
	int score;
	Hand h;
};