#include "Player.hpp"

Player::Player()
{
	//actiondeck_ = new Deck<ActionCard>();
	//pointdeck_ = new Deck<PointCard>();
	opponent_ = new Player();
	score_ = 0;
}

Player::~Player()
{
	delete opponent_;
	//delete[] actiondeck_;
	//delete[] pointdeck_;
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
	std::cout << "PLAYING ACTION CARD: " << card.getInstruction();
	if (card.isPlayable())
	{
		if (card.getInstruction().substr(0,4) == "DRAW")
		{
		}
		else if (card.getInstruction().substr(0, 4) == "PLAY")
		{
		}
		else if (card.getInstruction() == "REVERSE HAND")
		{
			hand_.Reverse();
		}
		else if (card.getInstruction() == "SWAP HAND WITH OPPONENT")
		{
		}
	}
}

void Player::drawPointCard()
{
	//hand_.addCard(pointdeck_->Draw());
}

void Player::playPointCard()
{
	
}

void Player::setOpponent(Player *opponent)
{
	opponent_ = opponent;
}

Player *Player::getOpponent()
{
	return opponent_;
}

void Player::setActionDeck(Deck<ActionCard> *actiondeck)
{
	actiondeck_ = actiondeck;
}

Deck<ActionCard> *Player::getActionDeck()
{
	return actiondeck_;
}

void Player::setPointDeck(Deck<PointCard> *pointdeck)
{
	pointdeck_ = pointdeck;
}

Deck<PointCard> *Player::getPointDeck()
{
	return pointdeck_;
}