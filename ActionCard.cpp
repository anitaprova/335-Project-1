#include "ActionCard.h"

ActionCard::ActionCard()
{
	set_type("action card");
	set_text("");
}

ActionCard::ActionCard(std::string p, std::string t, std::vector<int> v)
{
	set_type(p);
	set_text(t);
	set_image(v);
}

void ActionCard::play()
{
}