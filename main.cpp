#include <iostream>
#include "Card.hpp"
#include "ActionCard.hpp"
#include "PointCard.hpp"
#include "Deck.hpp"
#include "Hand.hpp"
#include "Player.hpp"

int main()
{
	int *p1_array = new int[80];
	int *p2_array = new int[80];
	int *p3_array = new int[80];
	int *p4_array = new int[80];
	int *p5_array = new int[80];

	int *a1_array = new int[80];
	int *a2_array = new int[80];
	int *a3_array = new int[80];
	int *a4_array = new int[80];
	int *a5_array = new int[80];
	int *a6_array = new int[80];
	int *a7_array = new int[80];
	int *a8_array = new int[80];
	for (int i = 0; i < 80; ++i)
	{
		p1_array[i] = i;
		p2_array[i] = i;
		p3_array[i] = i;
		p4_array[i] = i;
		p5_array[i] = i;

		a1_array[i] = i;
		a2_array[i] = i;
		a3_array[i] = i;
		a4_array[i] = i;
		a5_array[i] = i;
		a6_array[i] = i;
		a7_array[i] = i;
		a8_array[i] = i;
	}

	ActionCard a1;
	a1.setInstruction("DRAW 1 CARD(S)");
	a1.setImageData(a1_array);

	ActionCard a2;
	a2.setInstruction("PLAY 1 CARD(S)");
	a2.setImageData(a2_array);

	ActionCard a3;
	a3.setInstruction("REVERSE HAND");
	a3.setImageData(a3_array);

	ActionCard a4;
	a4.setInstruction("SWAP HAND WITH OPPONENT");
	a4.setImageData(a4_array);

	ActionCard a5;
	a5.setInstruction("DRAW 1 CARD(S)");
	a5.setImageData(a5_array);

	ActionCard a6;
	a6.setInstruction("PLAY 1 CARD(S)");
	a6.setImageData(a6_array);

	ActionCard a7;
	a7.setInstruction("REVERSE HAND");
	a7.setImageData(a7_array);

	ActionCard a8;
	a8.setInstruction("SWAP HAND WITH OPPONENT");
	a8.setImageData(a8_array);

	// Deck<ActionCard> da;
	// da.AddCard(a1);
	// da.AddCard(a2);
	// da.AddCard(a3);
	// da.AddCard(a4);
	// ActionCard deck_card = da.Draw();
	// std::cout << deck_card.getInstruction() << "\n";

	// for (auto x : da.getDeck())
	// {
	// 	x.Print();
	// }
	// std::cout << "\n\nSHUFFLE INCOMING \n\n";
	// da.Shuffle();
	// for (auto x : da.getDeck())
	// {
	// 	x.Print();
	// }
	// std::cout << "\\\\\\\\\\\\\\\\\\\\\\\\ \n\n\n";

	PointCard p; // empty

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

	PointCard p4;
	p4.setDrawn(true);
	p4.setInstruction("25");
	p4.setImageData(p4_array);

	PointCard p5;
	p5.setDrawn(true);
	p5.setInstruction("30");
	p5.setImageData(p5_array);

	// Hand h;
	// h.addCard(std::move(p)); // empty constructor
	// h.addCard(std::move(p1));
	// h.addCard(std::move(p2));
	// h.addCard(std::move(p3));

	// Deck<PointCard> dp;
	// dp.AddCard(p1);
	// dp.AddCard(p2);
	// dp.AddCard(p3);
	// dp.AddCard(p4);
	// dp.AddCard(p5);

	// h.addCard(dp.Draw());
	// h.addCard(dp.Draw());

	// for (auto &x : h.getCards())
	// {
	// 	x.Print();
	// }

	// std::cout << "\nREVERSE INCOMING"
	// 					<< "\n\n";

	// h.Reverse();
	// for (auto &x : h.getCards())
	// {
	// 	x.Print();
	// }
	//  std::cout << h.PlayCard() << "\n";
	//  std::cout << h.PlayCard() << "\n";
	//  std::cout << h.PlayCard() << "\n";
	//  std::cout << h.PlayCard() << "\n";

	Hand player_hand;
	Hand opp_hand;

	Player *player = new Player();
	Player *opp = new Player();
	player->setHand(player_hand);
	opp->setHand(opp_hand);
	player->setOpponent(opp);
	opp->setOpponent(player);

	Deck<ActionCard> da;
	da.AddCard(a1);
	da.AddCard(a2);
	da.AddCard(a3);
	da.AddCard(a4);
	da.AddCard(a5);
	da.AddCard(a6);
	da.AddCard(a7);
	da.AddCard(a8);

	player->setActionDeck(&da);
	opp->setActionDeck(&da);

	Deck<PointCard> dp;
	dp.AddCard(p1);
	dp.AddCard(p2);
	dp.AddCard(p3);
	dp.AddCard(p4);
	dp.AddCard(p5);
	player->setPointDeck(&dp);
	opp->setPointDeck(&dp);

	Hand example;
	example.addCard(dp.Draw());
	example.addCard(dp.Draw());
	example.addCard(dp.Draw());
	example.addCard(dp.Draw());
	example.addCard(dp.Draw());

	// for(auto x : example.getCards())
	// {
	// 	x.Print();
	// }

	// player->play(std::move(a1)); // draw
	player->play(std::move(a5)); // draw
	// for (auto x : player->getHand().getCards())
	// {
	// 	x.Print();
	// }
	// player->play(std::move(a3)); // reverse
	// for (auto x : player->getHand().getCards())
	// {
	// 	x.Print();
	// }

	// player->play(std::move(a2)); // play
	// std::cout << player->getScore() << "\n";

	// opp->play(std::move(a5));
	// std::cout << "player \n";
	// for (auto x : player->getHand().getCards())
	// {
	// 	x.Print();
	// }
	// std::cout << "opp \n";
	// for (auto x : opp->getHand().getCards())
	// {
	// 	x.Print();
	// }

	// player->play(std::move(a4)); // swap hands
	// for (auto x : player->getHand().getCards())
	// {
	// 	x.Print();
	// }
	// std::cout << "opp \n";
	// for (auto x : opp->getHand().getCards())
	// {
	// 	x.Print();
	// }

	return 0;
}