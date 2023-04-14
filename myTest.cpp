#include <stdexcept>
#include "sources/player.hpp"
#include "sources/game.hpp"
#include "sources/card.hpp"
using namespace std;
using namespace ariel;


int main()
{
    Player p1("Alice");
    Player p2("Bob");
    Game game(p1, p2);
}