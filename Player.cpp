#include "Player.hpp"

Player::Player()
{
	opponent_ = nullptr;
	actiondeck_ = nullptr;
	pointdeck_ = nullptr;
	// actiondeck_ = new Deck<ActionCard>();
	// pointdeck_ = new Deck<PointCard>();
	score_ = 0;
}

Player::~Player()
{
	delete opponent_;
	opponent_ = nullptr;

	delete actiondeck_;
	actiondeck_ = nullptr;

	delete pointdeck_;
	pointdeck_ = nullptr;
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
	std::string instruc = card.getInstruction();
	std::cout << "PLAYING ACTION CARD: " << card.getInstruction() << "\n";

	std::regex draw("^DRAW \\d+ CARD\\(S\\)");
	std::regex play("^PLAY \\d+ CARD\\(S\\)");

	std::regex num("\\d+");
	std::smatch match;
	std::regex_search(card.getInstruction().begin(), card.getInstruction().end(), match, num);
	if (std::regex_match(card.getInstruction(), draw))
	{
		for (int i = 0; i < std::stoi(match[0]); ++i)
		{
			drawPointCard();
		}
	}
	else if (std::regex_match(card.getInstruction(), play))
	{
		for (int i = 0; i < std::stoi(match[0]); ++i)
		{
			playPointCard();
		}
	}
	else if (card.getInstruction() == "REVERSE HAND")
	{
		hand_.Reverse();
	}
	else if (card.getInstruction() == "SWAP HAND WITH OPPONENT")
	{
		// Hand h = hand_;
		// hand_ = opponent_->hand_;
		// opponent_->setHand(h);
		std::swap(hand_, this->getOpponent()->hand_);
	}
}

void Player::drawPointCard()
{
	if (pointdeck_ != nullptr)
	{
		hand_.addCard(pointdeck_->Draw());
	}
}

void Player::playPointCard()
{
	if (!hand_.isEmpty())
	{
		score_ += hand_.PlayCard();
	}
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