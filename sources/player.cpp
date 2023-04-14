#include "player.hpp"
using namespace ariel;

Player ::Player(string name){
    _name = name;
};

int Player::stacksize()
{
	int ret = _hand.size();
	return ret;
};

int Player::cardesTaken()
{
    return _results.size();
};


void Player::addCard(Card extra)
{
	_hand.insert(_hand.begin(),extra);
    return ;
};