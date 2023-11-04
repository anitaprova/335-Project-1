#include <iostream>
#include "Card.hpp"
#include "ActionCard.hpp"
#include "PointCard.hpp"
#include "Deck.hpp"
#include "Hand.hpp"
// #include "Player.hpp"

// #include <algorithm>
// #include <iterator>
// #include<random>
// #include <vector>

int main()
{
	int *p1_array = new int[80];
	int *p2_array = new int[80];
	int *p3_array = new int[80];

	int *a1_array = new int[80];
	int *a2_array = new int[80];
	int *a3_array = new int[80];
	int *a4_array = new int[80];
	for (int i = 0; i < 80; ++i)
	{
		p1_array[i] = i;
		p2_array[i] = i;
		p3_array[i] = i;

		a1_array[i] = i;
		a2_array[i] = i;
		a3_array[i] = i;
		a4_array[i] = i;
	}

	ActionCard a1;
	a1.setDrawn(true);
	a1.setInstruction("PLAY 1 CARD(S)");
	a1.setImageData(a1_array);

	ActionCard a2;
	a2.setDrawn(true);
	a2.setInstruction("PLAY 2 CARD(S)");
	a2.setImageData(a2_array);

	ActionCard a3;
	a3.setDrawn(true);
	a3.setInstruction("PLAY 3 CARD(S)");
	a3.setImageData(a3_array);

	ActionCard a4;
	a4.setDrawn(true);
	a4.setInstruction("PLAY 3 CARD(S)");
	a4.setImageData(a4_array);

	Deck<ActionCard> da;
	// std::cout << da.IsEmpty() << "\n";
	// std::cout << da.getSize() << "\n";
	da.AddCard(a1);
	da.AddCard(a2);
	da.AddCard(a3);
	da.AddCard(a4);
	// std::cout << da.IsEmpty() << "\n";
	// std::cout << da.getSize() << "\n";
	// ActionCard &&deck_card = da.Draw();
	// std::cout << deck_card.getInstruction() << "\n";

	// for (auto x : da.getDeck())
	// {
	// 	x.Print();
	// }
	// da.Shuffle();
	// for (auto x : da.getDeck())
	// {
	// 	x.Print();
	// }

	PointCard p1;
	p1.setDrawn(true);
	p1.setInstruction("5");
	p1.setImageData(p1_array);

	PointCard p2;
	p2.setDrawn(true);
	p2.setInstruction("15");
	p2.setImageData(p2_array);

	PointCard p3;
	p3.setDrawn(true);
	p3.setInstruction("20");
	p3.setImageData(p3_array);

	Hand h;
	h.addCard(std::move(p1));
	h.addCard(std::move(p2));
	h.addCard(std::move(p3));

	for (auto &x : h.getCards())
	{
		x.Print();
	}

	std::cout << "\nREVERSE INCOMING" << "\n\n";

	h.Reverse();
	for (auto &x : h.getCards())
	{
		x.Print();
	}
	std::cout << h.PlayCard() << "\n";

	return 0;
}