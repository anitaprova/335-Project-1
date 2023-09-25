#pragma once
#include <string>
#include <vector>

class Card // abstract class
{
public:
	Card();
	~Card();
	Card(const Card &rhs); // copy constructor
	Card &operator=(const Card &rhs);
	Card(Card &&rhs); // move constructor
	Card &operator=(Card &&rhs);

	virtual void play(); // pure virtual function so not defined here
	std::string get_type();
	std::string get_text();
	void set_type(std::string s);
	void set_text(std::string s);
	void set_image(std::vector<int> i);

private:
	std::string type;
	std::string text;
	std::vector<int> *image;
};