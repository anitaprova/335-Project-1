#include <iostream>
#include "Card.hpp"
#include "Deck.hpp"
#include "ActionCard.hpp"
#include "PointCard.hpp"

/*
#include "Hand.hpp"
#include "Player.hpp"
*/

int main()
{
	ActionCard *a = new ActionCard();
	a->setDrawn(1);
	a->setInstruction("PLAY 3 CARD(S)");
	a->Print();
	std::cout << a->isPlayable() << "\n\n\n";

	PointCard *p = new PointCard();
	p->setDrawn(1);
	p->setInstruction("5");
	p->Print();
	p->isPlayable();

	return 0;
}