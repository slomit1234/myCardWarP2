#ifndef CARD_HPP
#define CARD_HPP

#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <algorithm>
#include <chrono>
#include <random>
using namespace std;


namespace ariel
{

    class Card
    {

    public:
        Card(int value, string type);
        int compareto(Card second);
        string getSuit();
        int getRank();
        void flip();

    private:
        bool _isFaceUp;
        int _rank;
        string _suit;

    };

}

#endif