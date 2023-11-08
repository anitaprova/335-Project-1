# The Card Game
Action Cards contain instructions in one following forms, where x is a positive integer: DRAW x CARD(S), PLAY x CARD(S), REVERSE HAND, or SWAP HAND WITH OPPONENT. 

Point Cards contain a whole number representing the number of points scored when a Player plays a Point Card from their hand. The only way for a Player to play a card from their hand
is through an Action Card Instruction

A Hand belonging to a player only contains point cards, and maintains order so cards drawn first are scored first. The only way for a Player to add a Point card to their hand is through an Action Card instruction

A Deck holds either Point Cards or Action Cards.

Players contain their score, hand of cards, pointers to their opponent, a Point Deck, and an Action Deck. 