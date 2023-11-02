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
	for (int i = 0; i < 80; ++i)
	{
		b[i] = i;
		b1[i] = i;
		b2[i] = i;
		b3[i] = i;

		a_array[i] = i;
		a1_array[i] = i;
	}

	ActionCard a1;
	a1.setDrawn(1);
	a1.setInstruction("PLAY 5 CARD(S)");
	a1.setImageData(a_array);
	//a1.Print();
	//std::cout << a1.isPlayable() << "\n\n";

	ActionCard a2;
	a2.setDrawn(1);
	a2.setInstruction("PLAY 3 CARD(S)");
	a2.setImageData(a1_array);

	Deck<ActionCard> da;
	std::cout << da.IsEmpty() << "\n";
	std::cout << da.getSize() << "\n";
	da.AddCard(a1);
	da.AddCard(a2);
	std::cout << da.getSize() << "\n";
	for (auto &x : da.getDeck())
	{
		x.Print();
	}
	
	da.Shuffle();
	//

	PointCard p;
	p.setDrawn(1);
	p.setInstruction("5");
	p.setImageData(b1);
	//p.Print();
	//std::cout << p.isPlayable() << "\n\n";

	PointCard p2;
	//std::cout << p2.getInstruction();
	p2.setDrawn(1);
	p2.setInstruction("15");
	p2.setImageData(b2);

	PointCard p3;
	//std::cout << p2.getInstruction();
	p3.setDrawn(1);
	p3.setInstruction("20");
	p3.setImageData(b3);

	/*Hand h;
	h.addCard(std::move(p));
	//h.getCards().front().Print();
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