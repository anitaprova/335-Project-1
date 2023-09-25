#pragma once
#include "PointCard.h"
#include <deque>

class Hand
{
public:
	Hand();
	~Hand();
	Hand(const Hand &rhs); // copy constructor
	Hand &operator=(const Hand &rhs);
	Hand(Hand &&rhs); // move constructor
	Hand &operator=(Hand &&rhs);

	void reverse();
	void PlayCard();

private:
	std::deque<PointCard> d; //not sure about this
};