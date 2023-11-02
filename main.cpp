#include <iostream>
#include "Card.hpp"
#include "ActionCard.hpp"
#include "PointCard.hpp"
#include "Deck.hpp"
#include "Hand.hpp"
//#include "Player.hpp"


int main()
{
	int *b = new int[80];
	int *b1 = new int[80];
	int *b2 = new int[80];
	int *b3 = new int[80];

	int *a_array = new int[80];
	int *a1_array = new int[80];
	int *a2_array = new int[80];
	for (int i = 0; i < 80; ++i)
	{
		b[i] = i;
		b1[i] = i;
		b2[i] = i;
		b3[i] = i;

		a_array[i] = i;
		a1_array[i] = i;
		a2_array[i] = i;
	}

	ActionCard a1;
	a1.setDrawn(1);
	a1.setInstruction("PLAY 5 CARD(S)");
	a1.setImageData(a_array);

	ActionCard a2;
	a2.setDrawn(1);
	a2.setInstruction("PLAY 3 CARD(S)");
	a2.setImageData(a1_array);

	ActionCard a3;
	a3.setDrawn(1);
	a3.setInstruction("PLAY 3 CARD(S)");
	a3.setImageData(a2_array);

	Deck<ActionCard> da;
	std::cout << da.IsEmpty() << "\n";
	std::cout << da.getSize() << "\n";
	da.AddCard(a1);
	da.AddCard(a2);
	da.AddCard(a3);
	std::cout << da.getSize() << "\n";
	ActionCard &&deck_card = da.Draw();
	std::cout << deck_card.getInstruction() << "\n";
	
	//da.Shuffle();
	/*for (auto &x : da.getDeck())
	{
		x.Print();
	}*/
	
	PointCard p;
	p.setDrawn(1);
	p.setInstruction("5");
	p.setImageData(b1);

	PointCard p2;
	p2.setDrawn(1);
	p2.setInstruction("15");
	p2.setImageData(b2);

	PointCard p3;
	p3.setDrawn(1);
	p3.setInstruction("20");
	p3.setImageData(b3);

	/*Hand h;
	h.addCard(std::move(p));
	h.addCard(std::move(p2));
	h.addCard(std::move(p3));

	std::cout << h.getCards().size() << "\n";
	for (auto &x : h.getCards())
	{
		x.Print();
	}
	std::cout << "REVERSE INCOMING" <<"\n\n\n";

	h.Reverse();
	for(auto &x: h.getCards())
	{
		x.Print();
	}
	//std::cout << h.PlayCard() << "\n";
	*/
	
	return 0;
}