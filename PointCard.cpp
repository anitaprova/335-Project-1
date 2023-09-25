#include "PointCard.h"

PointCard::PointCard()
{
	set_type("Point");
}

PointCard::PointCard(std::string p, std::string t, std::vector<int> v)
{
	set_type(p);
	set_text(t);
	set_image(v);
}

void PointCard::play()
{
	
}