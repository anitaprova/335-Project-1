#include "Card.h"

// constructor
Card::Card()
{
	type = "";
	text = "";
	image = new std::vector<int>;
}

// deconstructor
Card::~Card()
{
	delete[] image;
}

// copy constructor
Card::Card(const Card &rhs)
{
	text = rhs.text;
	type = rhs.text;
	image = new std::vector<int>;
	for (auto i = image->begin(); i != image->end(); ++i) // not sure about this
	{
		image = rhs.image;
	}
}

// copy constructor assignment operator
Card &Card::operator=(const Card &rhs)
{
	if (this != &rhs)
	{
		delete[] image;
		text = rhs.text;
		type = rhs.type;
		image = new std::vector<int>;
		for (auto i = image->begin(); i != image->end(); ++i)
		{
			image = rhs.image;
		}
	}
	return *this;
}

// move constructor
Card::Card(Card &&rhs)
{
	text = rhs.text;
	type = rhs.type;
	image = rhs.image;
	rhs.image = nullptr;
}

// move constructor assignment operator
Card &Card::operator=(Card &&rhs)
{
	if (this != &rhs)
	{
		text = rhs.text;
		type = rhs.type;
		image = rhs.image;
		rhs.image = nullptr;
	}
	return *this;
}

std::string Card::get_type()
{
	return type;
}

std::string Card::get_text()
{
	return text;
}

void Card::set_type(std::string s)
{
	type = s;
}

void Card::set_text(std::string s)
{
	text = s;
}

void Card::play() //'defining' it here so makefile doesnt freak out
{

}

void Card::set_image(std::string s)
{
	
}