#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include "Card.h"
#include "Deck.h"
#include "ActionCard.h"
#include "PointCard.h"
#include "Hand.h"
#include "Player.h"

int main()
{
	std::ifstream in_file;

	// Deck<Card> *deck = new Deck<Card>();
	std::string type = "";
	std::string text = "";
	std::vector<int> image;
	int copies = 0;
	std::string shuffle = "";

	in_file.open("input1");
	std::string line = "";
	while (getline(in_file, line)) // reads from file and makes the deck
	{
		if (line.find("type:") != std::string::npos)
		{
			type = line.substr(line.find(":") + 2);
		}
		else if (line.find("text:") != std::string::npos)
		{
			text = line.substr(line.find(":") + 2);
		}
		else if (line.find("image:") != std::string::npos)
		{
			std::stringstream s(line.substr(line.find(":") + 2));
			std::string i;
			while (s >> i)
			{
				image.push_back(stoi(i));
			}
		}
		else if (line.find("copies:") != std::string::npos)
		{
			copies = stoi(line.substr(line.find(":") + 2));
			if (type == "action card")
			{
				for (int i = 0; i < copies; i++)
				{
					// deck.addCard(new ActionCard(type, text, image));
					ActionCard *a = new ActionCard();
				}
			}
			else
			{
				for (int i = 0; i < copies; i++)
				{
					// PointCard *p = new PointCard();
				}
			}
		}

		if (line.find("shuffle:") != std::string::npos)
		{
			shuffle = line.substr(line.find(":") + 1);
		}
	}

	return 0;
}