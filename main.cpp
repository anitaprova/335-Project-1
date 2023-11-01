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
	int *b = new int[80];
	int *bb = new int[80];
	for (int i = 0; i < 80; ++i)
	{
		b[i] = i;
		bb[i] = i;
	}

	ActionCard a;
	a.setDrawn(1);
	a.setInstruction("PLAY 3 CARD(S)");
	a.setImageData(b);
	a.Print();
	std::cout << a.isPlayable() << "\n\n";

	PointCard p;
	std::cout << p.getInstruction();
	p.setDrawn(1);
	p.setInstruction("5");
	p.setImageData(bb);
	p.Print();
	std::cout << p.isPlayable() << "\n\n";

	//Deck<PointCard> dp;
	//dp.AddCard(p);

	return 0;
}