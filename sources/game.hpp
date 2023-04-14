#ifndef GAME_HPP
#define GAME_HPP

#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <vector>
#include <algorithm>
#include <string.h>
#include <random>
#include <map>
#include <bits/stdc++.h>
using namespace std;

#include "player.hpp"
#include "card.hpp"

namespace ariel
{
    class Game
    {
        public:
            Game(Player& player1, Player& player2);
            void playTurn();
            string printLastTurn();
            string printStats();
            string printLog();
            string printWiner();
            void playAll();
            multimap <string, string> _turns;
			Player &_p1;
			Player &_p2;
			bool _gameIsActive;
			bool isDraw;
			vector<Card> _hold;
			vector<Card> deck;
            
    };
}

#endif