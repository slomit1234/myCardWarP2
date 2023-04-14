#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <vector>
#include <list>
#include "card.hpp"

using namespace std;
namespace ariel{
    class Player
    {

    public:
        //Player(){_name = "Anonymous";} //defult constructor
        Player(string name);
        int stacksize();
        int cardesTaken();
        void addCard(Card extra);
		string _name;
        vector<Card> _hand;
        vector<Card> _results;
        int _statCardsKept;
        int _statCardsGained;
    };
}

#endif

