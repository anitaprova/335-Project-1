#include <iostream>
#include "Card.hpp"
#include "ActionCard.hpp"
#include "PointCard.hpp"
#include "Deck.hpp"
//#include "Hand.hpp"
//#include "Player.hpp"


int main()
{
	int *b = new int[80];
	int *b1 = new int[80];
	int *b2 = new int[80];
	for (int i = 0; i < 80; ++i)
	{
		b[i] = i;
		b1[i] = i;
		b2[i] = i;
	}

	ActionCard a;
	a.setDrawn(1);
	a.setInstruction("PLAY 3 CARD(S)");
	a.setImageData(b);
	//a.Print();
	//std::cout << a.isPlayable() << "\n\n";

	PointCard p;
	p.setDrawn(1);
	p.setInstruction("5");
	p.setImageData(b1);
	//p.Print();
	//std::cout << p.isPlayable() << "\n\n";

	PointCard p2;
	std::cout << p2.getInstruction();
	p2.setDrawn(1);
	p2.setInstruction("5");
	p2.setImageData(b2);

	Deck<ActionCard> *da;
	//da->AddCard(a);

	//Hand h;
	//h.addCard(std::move(p));
	//h.addCard(std::move(p2));

	return 0;
}