#include "Player.hpp"

Player::Player()
{
	score_ = 0;
}

Player::~Player()
{
	delete opponent_;
	delete[] actiondeck_;
	delete[] pointdeck_;
}

const Hand &Player::getHand() const
{
	return hand_;
}

void Player::setHand(const Hand &hand)
{
	hand_ = hand;
}

int Player::getScore() const
{
	return score_;
}

void Player::setScore(const int &score)
{
	score_ = score;
}

void Player::play(ActionCard &&card)
{
}

void Player::drawPointCard()
{
}

void Player::playPointCard()
{
}

void Player::setOpponent(Player *opponent)
{
}

Player *Player::getOpponent()
{
}

void Player::setActionDeck(Deck<ActionCard> *actiondeck)
{
}

Deck<ActionCard> *Player::getActionDeck()
{
}

void Player::setPointDeck(Deck<PointCard> *pointdeck)
{
}

Deck<PointCard> *Player::getPointDeck()
{
}