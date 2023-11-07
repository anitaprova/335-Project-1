#include "Player.hpp"

/**
 * @post: Construct a new Player object
 */
Player::Player()
{
	opponent_ = nullptr;
	actiondeck_ = nullptr;
	pointdeck_ = nullptr;
	score_ = 0;
}

/**
 * @post: Destroy the Player object
 */
Player::~Player()
{
	opponent_ = nullptr;

	delete actiondeck_;
	actiondeck_ = nullptr;

	delete pointdeck_;
	pointdeck_ = nullptr;
}

/**
 * @return the player's hand
 */
const Hand &Player::getHand() const
{
	return hand_;
}

/**
 * @post: Set the player's hand
 * @param const reference to a hand object
 */
void Player::setHand(const Hand &hand)
{
	hand_ = hand;
}

/**
 * @return the Player's current score
 */
int Player::getScore() const
{
	return score_;
}

/**
 * @post: Set the player's score
 * @param: score
 */
void Player::setScore(const int &score)
{
	score_ = score;
}

/**
 * @post: Play a given action card
 * @param: an Actioncard object
 * Begin the function by reporting the instruction of the card:
 * PLAYING ACTION CARD: [instruction]
 */
void Player::play(ActionCard &&card)
{
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
		std::swap(hand_, this->getOpponent()->hand_);
	}
}

/**
 * @post: Draw a point card and place it in the player's hand
 */
void Player::drawPointCard()
{
	if (pointdeck_ != nullptr)
	{
		hand_.addCard(pointdeck_->Draw());
	}
}

/**
 * @post: Play a point card from the player's hand and update the player's score
 */
void Player::playPointCard()
{
	if (!hand_.isEmpty())
	{
		score_ += hand_.PlayCard();
	}
}

/**
 * @post: Set the opponent of the player
 * @param a pointer to a Player opponent
 */
void Player::setOpponent(Player *opponent)
{
	opponent_ = opponent;
}

/**
 * @return: a pointer to the player's opponent
 */
Player *Player::getOpponent()
{
	return opponent_;
}

/**
 * @post: set the action deck of the player
 * @param: A pointer to a deck holding Action cards
 */
void Player::setActionDeck(Deck<ActionCard> *actiondeck)
{
	actiondeck_ = actiondeck;
}

/**
 * @return a pointer to the player's action deck
 */
Deck<ActionCard> *Player::getActionDeck()
{
	return actiondeck_;
}

/**
 * @post: set the point deck of the player
 * @param: A pointer to a deck holding Point cards
 */
void Player::setPointDeck(Deck<PointCard> *pointdeck)
{
	pointdeck_ = pointdeck;
}

/**
 * @return: a pointer to the player's point deck
 */
Deck<PointCard> *Player::getPointDeck()
{
	return pointdeck_;
}