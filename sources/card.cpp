#include "card.hpp"
using namespace ariel;

Card ::Card(int value, string type)
{
	_isFaceUp=true;
	_suit=type;
	_rank=value;
};

int Card::compareto(Card second)
{
	return 0;
};

int Card::getRank()
{
	return _rank;
};

string Card::getSuit()
{
	return _suit;
};

void Card::flip()
{
	_isFaceUp=!_isFaceUp;
};

