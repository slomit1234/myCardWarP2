#include "game.hpp"
using namespace ariel;

//enum Suit {CLUBS, DIAMONDS, HEARTS, SPADES};

Game ::Game(Player&p1, Player&p2) : _p1(p1), _p2(p2)
{
	//initilize class var's
	//creating the cards stash
	for(int i=0; i<4; i++) //suit
	{
		for(int j=1; j<=13; j++)
		{
			switch (i) {
				case 0:
				{
					deck.push_back(Card(j,"CLUBS"));
					break;
				}
				case 1:
				{
					deck.push_back(Card(j,"DIAMONDS"));
					break;
				}
				case 2:
				{
					deck.push_back(Card(j,"HEARTS"));
					break;
				}
				case 3:
				{
					deck.push_back(Card(j,"SPADES"));
					break;
				}


			}
		}
	}

	//suffle the deck randomly
	random_device rd;
	mt19937 gen(rd());
	shuffle(deck.begin(),deck.end(), gen);


	//divide the shuffled stash to the players
	vector<Card>::size_type numCardsPerPlayer = deck.size() / 2;
	for(vector<Card>::size_type i=0; i<numCardsPerPlayer; i++)
	{
		_p1.addCard(deck[i]);
		_p2.addCard(deck[numCardsPerPlayer + i]);
	}

	//check
	for(vector<Card>::size_type j=0; j<numCardsPerPlayer; j++)
	{
		//cout << to_string(j)+"p1: "+to_string(_p1._hand[j]->getRank())+" p2: "+to_string(_p2._hand[j]->getRank())+"...";
	}

	_gameIsActive = true;
	isDraw = false;

};

void Game::playTurn()
{
	if(_p1._hand.size() != 0 && _p2._hand.size() != 0 && _gameIsActive)
	{
		//check if its the same player - if is, throws exeption #try do a better condition
		if(&_p1 == &_p2)
		{
			__throw_logic_error("Cant start new game with 1 player");
		}
		string log;
		Card Cp1 = _p1._hand.at(_p1._hand.size()-1);
		Card Cp2 = _p2._hand.at(_p1._hand.size()-1);

		int res = Cp2.getRank() - Cp1.getRank();
		if ((Cp1.getRank()==1 || Cp2.getRank()==1 ) && !(Cp1.getRank()==2 || Cp2.getRank()==2) && res != 0)
		{
			if(Cp1.getRank()==1)
			{
				res = -1;
			}
			else
			{
				res = 1;
			}
		}
		if(res>0) // p2 won
		{

			if(_hold.size() != 0)
			{
				_p2._statCardsGained = (_hold.size())/2;
				_p2._statCardsKept = (_hold.size())/2;

				_p2._results.insert(_p2._results.end(),_hold.begin(),_hold.end());

				_hold.clear();

			}

			_p2._results.push_back(Cp1);
			_p2._results.push_back(Cp2);

			//# delete the elements from hands
			_p1._hand.erase(std::next(_p1._hand.end()));
			_p2._hand.erase(std::next(_p2._hand.end()));

			_p2._statCardsGained+=1;
			_p2._statCardsKept+=1;
			if(Cp1.getRank()>10 && Cp2.getRank()>10)
			{
				if(Cp1.getRank()==11)
				{
					log = _p1._name + " played PRINCE of " +  Cp1.getSuit() +" "+ _p2._name + " played " + to_string(Cp2.getRank()) + " of " + Cp2.getSuit() +". "+ _p2._name +" wins.";
				}
				else if(Cp1.getRank() == 12)
				{
					log = _p1._name + " played QUEEN of " +  Cp1.getSuit() +" "+ _p2._name + " played " + to_string(Cp2.getRank()) + " of " + Cp2.getSuit() +". "+ _p2._name +" wins.";
				}
				else
				{
					log = _p1._name + " played KING of " +  Cp1.getSuit() +" "+ _p2._name + " played " + to_string(Cp2.getRank()) + " of " + Cp2.getSuit() +". "+ _p2._name +" wins.";
				}

				if(Cp2.getRank()==11)
				{
					log = _p1._name + " played PRINCE of " +  Cp1.getSuit() +" "+ _p2._name + " played " + to_string(Cp2.getRank()) + " of " + Cp2.getSuit() +". "+ _p2._name +" wins.";
				}
				else if(Cp2.getRank() == 12)
				{
					log = _p1._name + " played QUEEN of " +  Cp1.getSuit() +" "+ _p2._name + " played " + to_string(Cp2.getRank()) + " of " + Cp2.getSuit() +". "+ _p2._name +" wins.";
				}
				else
				{
					log = _p1._name + " played KING of " +  Cp1.getSuit() +" "+ _p2._name + " played " + to_string(Cp2.getRank()) + " of " + Cp2.getSuit() +". "+ _p2._name +" wins.";
				}

			}
			else if(Cp2.getRank()>10)
			{
				if(Cp2.getRank()==11)
				{
					log = _p1._name + " played PRINCE of " +  Cp1.getSuit() +" "+ _p2._name + " played " + to_string(Cp2.getRank()) + " of " + Cp2.getSuit() +". "+ _p2._name +" wins.";
				}
				else if(Cp2.getRank() == 12)
				{
					log = _p1._name + " played QUEEN of " +  Cp1.getSuit() +" "+ _p2._name + " played " + to_string(Cp2.getRank()) + " of " + Cp2.getSuit() +". "+ _p2._name +" wins.";
				}
				else
				{
					log = _p1._name + " played KING of " +  Cp1.getSuit() +" "+ _p2._name + " played " + to_string(Cp2.getRank()) + " of " + Cp2.getSuit() +". "+ _p2._name +" wins.";
				}
			}
			else if(Cp1.getRank()>10)
			{
				if(Cp1.getRank()==11)
				{
					log = _p1._name + " played PRINCE of " +  Cp1.getSuit() +" "+ _p2._name + " played " + to_string(Cp2.getRank()) + " of " + Cp2.getSuit() +". "+ _p2._name +" wins.";
				}
				else if(Cp1.getRank() == 12)
				{
					log = _p1._name + " played QUEEN of " +  Cp1.getSuit() +" "+ _p2._name + " played " + to_string(Cp2.getRank()) + " of " + Cp2.getSuit() +". "+ _p2._name +" wins.";
				}
				else
				{
					log = _p1._name + " played KING of " +  Cp1.getSuit() +" "+ _p2._name + " played " + to_string(Cp2.getRank()) + " of " + Cp2.getSuit() +". "+ _p2._name +" wins.";
				}
			}
			else
			{

				log = _p1._name + " played " + to_string(Cp1.getRank()) + " of " + Cp1.getSuit() + " "+ _p2._name + " played " + to_string(Cp2.getRank()) + " of " +Cp2.getSuit() +". "+ _p2._name +" wins.";
			}
			if(isDraw)
			{
				//map<string,string>::iterator a = _turns.end();
				//log = " "+log;
				string s = (--_turns.end())->second;
				string tstr = s+" "+log;
				_turns.erase(--_turns.end());
				_turns.insert(pair<string,string>(_p2._name,tstr));
				isDraw=false;
			}
			else
			{
				_turns.insert(pair<string,string>(_p2._name,log));
			}

		}
		else if (res<0) // p1 won
		{
			if(_hold.size() != 0)
			{
				_p1._statCardsGained = (_hold.size())/2;
				_p1._statCardsKept = (_hold.size())/2;

				_p1._results.insert(_p1._results.end(),_hold.begin(),_hold.end());

				_hold.clear();

			}

			_p1._results.push_back(Cp1);
			_p1._results.push_back(Cp2);

			//# delete the elements from hands
			_p1._hand.erase(std::next(_p1._hand.end()));
			_p2._hand.erase(std::next(_p2._hand.end()));

			_p1._statCardsGained+=1;
			_p1._statCardsKept+=1;

			if(Cp1.getRank()>10 && Cp2.getRank()>10)
			{
				if(Cp1.getRank()==11)
				{
					log = _p1._name + " played PRINCE of " +  Cp1.getSuit() +" "+ _p2._name + " played " + to_string(Cp2.getRank()) + " of " + Cp2.getSuit() +". "+ _p1._name +" wins.";
				}
				else if(Cp1.getRank() == 12)
				{
					log = _p1._name + " played QUEEN of " +  Cp1.getSuit() +" "+ _p2._name + " played " + to_string(Cp2.getRank()) + " of " + Cp2.getSuit() +". "+ _p1._name +" wins.";
				}
				else
				{
					log = _p1._name + " played KING of " +  Cp1.getSuit() +" "+ _p2._name + " played " + to_string(Cp2.getRank()) + " of " + Cp2.getSuit() +". "+ _p1._name +" wins.";
				}

				if(Cp2.getRank()==11)
				{
					log = _p1._name + " played PRINCE of " +  Cp1.getSuit() +" "+ _p2._name + " played " + to_string(Cp2.getRank()) + " of " + Cp2.getSuit() +". "+ _p1._name +" wins.";
				}
				else if(Cp2.getRank() == 12)
				{
					log = _p1._name + " played QUEEN of " +  Cp1.getSuit() +" "+ _p2._name + " played " + to_string(Cp2.getRank()) + " of " + Cp2.getSuit() +". "+ _p1._name +" wins.";
				}
				else
				{
					log = _p1._name + " played KING of " +  Cp1.getSuit() +" "+ _p2._name + " played " + to_string(Cp2.getRank()) + " of " + Cp2.getSuit() +". "+ _p1._name +" wins.";
				}

			}
			else if(Cp2.getRank()>10)
			{
				if(Cp2.getRank()==11)
				{
					log = _p1._name + " played PRINCE of " +  Cp1.getSuit() +" "+ _p2._name + " played " + to_string(Cp2.getRank()) + " of " + Cp2.getSuit() +". "+ _p1._name +" wins.";
				}
				else if(Cp2.getRank() == 12)
				{
					log = _p1._name + " played QUEEN of " +  Cp1.getSuit() +" "+ _p2._name + " played " + to_string(Cp2.getRank()) + " of " + Cp2.getSuit() +". "+ _p1._name +" wins.";
				}
				else
				{
					log = _p1._name + " played KING of " +  Cp1.getSuit() +" "+ _p2._name + " played " + to_string(Cp2.getRank()) + " of " + Cp2.getSuit() +". "+ _p1._name +" wins.";
				}
			}
			else if(Cp1.getRank()>10)
			{
				if(Cp1.getRank()==11)
				{
					log = _p1._name + " played PRINCE of " +  Cp1.getSuit() +" "+ _p2._name + " played " + to_string(Cp2.getRank()) + " of " + Cp2.getSuit() +". "+ _p1._name +" wins.";
				}
				else if(Cp1.getRank() == 12)
				{
					log = _p1._name + " played QUEEN of " +  Cp1.getSuit() +" "+ _p2._name + " played " + to_string(Cp2.getRank()) + " of " + Cp2.getSuit() +". "+ _p1._name +" wins.";
				}
				else
				{
					log = _p1._name + " played KING of " +  Cp1.getSuit() +" "+ _p2._name + " played " + to_string(Cp2.getRank()) + " of " + Cp2.getSuit() +". "+ _p1._name +" wins.";
				}
			}
			else
			{

				log = _p1._name + " played " +to_string(Cp1.getRank())+ " of " +  Cp1.getSuit() +" "+ _p2._name + " played " + to_string(Cp2.getRank()) + " of " + Cp2.getSuit() +". "+ _p1._name +" wins.";
				//Alice played 6 of Hearts Bob played 6 of Spades. Draw.
			}
			if(isDraw)
			{
				string s = (--_turns.end())->second;

				string tstr = s+" "+log;
				_turns.erase(--_turns.end());
				_turns.insert(pair<string,string>(_p2._name,tstr));
				isDraw=false;
			}
			else
			{
				_turns.insert(pair<string,string>(_p1._name,log));
			}

		}
		else //tie
		{
			if(Cp1.getRank()>10 && Cp2.getRank()>10)
			{
				if(Cp1.getRank()==11)
				{
					log = _p1._name + " played PRINCE of " +  Cp1.getSuit() +" ";}
				else if(Cp1.getRank() == 12)
				{
					log = _p1._name + " played QUEEN of " +  Cp1.getSuit() +" ";
				}
				else
				{
					log = _p1._name + " played KING of " +  Cp1.getSuit() +" ";}

				if(Cp2.getRank()==11)
				{
					log = log + _p2._name + " played " + to_string(Cp2.getRank()) + " of " + Cp2.getSuit() +". "+" Draw.";}
				else if(Cp2.getRank() == 12)
				{
					log =log + _p2._name + " played " + to_string(Cp2.getRank()) + " of " + Cp2.getSuit() +". "+" Draw.";}
				else
				{
					log = log + _p2._name + " played " + to_string(Cp2.getRank()) + " of " + Cp2.getSuit() +". "+" Draw.";}

			}
			else if(Cp2.getRank()>10)
			{
				if(Cp2.getRank()==11)
				{
					log = _p1._name + " played PRINCE of " +  Cp1.getSuit() +" "+ _p2._name + " played " + to_string(Cp2.getRank()) + " of " + Cp2.getSuit() +". "+" Draw.";}
				else if(Cp2.getRank() == 12)
				{
					log = _p1._name + " played QUEEN of " +  Cp1.getSuit() +" "+ _p2._name + " played " + to_string(Cp2.getRank()) + " of " + Cp2.getSuit() +". "+" Draw.";}
				else
				{
					log = _p1._name + " played KING of " +  Cp1.getSuit() +" "+ _p2._name + " played " + to_string(Cp2.getRank()) + " of " + Cp2.getSuit() +". "+" Draw.";}
			}
			else if(Cp1.getRank()>10)
			{
				if(Cp1.getRank()==11)
				{
					log = _p1._name + " played PRINCE of " +  Cp1.getSuit() +" "+ _p2._name + " played " + to_string(Cp2.getRank()) + " of " + Cp2.getSuit() +". "+" Draw.";}
				else if(Cp1.getRank() == 12)
				{
					log = _p1._name + " played QUEEN of " +  Cp1.getSuit() +" "+ _p2._name + " played " + to_string(Cp2.getRank()) + " of " + Cp2.getSuit() +". "+" Draw.";}
				else
				{
					log = _p1._name + " played KING of " +  Cp1.getSuit() +" "+ _p2._name + " played " + to_string(Cp2.getRank()) + " of " + Cp2.getSuit() +". "+" Draw.";}
			}
			else
			{

				log = _p1._name + " played " + to_string(Cp1.getRank()) + " of " + Cp1.getSuit() + " "+ _p2._name + " played " + to_string(Cp2.getRank()) + " of " +Cp2.getSuit() +". "+". Draw.";
			}
			_turns.insert(pair<string,string>("TIE",log));
			isDraw = true;

			if(_p1._hand.size() < 3 && _p2._hand.size() < 3)
			{
				_p1._statCardsKept += 2;
				_p2._statCardsKept += 2;

				_p1._results.insert(_p1._results.end(),_p1._hand.begin(),_p1._hand.end());
				_p2._results.insert(_p2._results.end(),_p2._hand.begin(),_p2._hand.end());

				//# delete the elements from hands
				_p1._hand.clear();
				_p2._hand.clear();


				if(_hold.size() != 0)
				{
					_p1._statCardsGained = (_hold.size())/4;
					_p1._statCardsKept = (_hold.size())/4;
					_p2._statCardsGained = (_hold.size())/4;
					_p2._statCardsKept = (_hold.size())/4;
					vector<Card>::iterator num = _hold.begin();
					unsigned long n = 0;
					while(n < ((_hold.size())/4 -1))
					{
						n++;
						num++;
					}
					_p1._results.insert(_p1._results.end(),_hold.begin(),num);
					num++;
					_p2._results.insert(_p2._results.end(),num,_hold.end());

					_hold.clear();

				}
				_gameIsActive = false;
			}
			else
			{

				_hold.push_back(Cp1);
				_hold.push_back(Cp2);
				//# delete the elements from hands
				_p1._hand.erase(std::next(_p1._hand.end()));
				_p2._hand.erase(std::next(_p2._hand.end()));

				Card pp1 = _p1._hand.at(_p1._hand.size()-1);
				Card pp2 = _p2._hand.at(_p2._hand.size()-1);

				pp1.flip();
				pp2.flip();

				_hold.push_back(pp1);
				_hold.push_back(pp2);

				//# delete the elements from hands
				_p1._hand.erase(std::next(_p1._hand.end()));
				_p2._hand.erase(std::next(_p2._hand.end()));

				playTurn();
			}

		}

	}
	else
	{
		if(!_gameIsActive)
		{
			__throw_logic_error("Cant activate a done game");
		}
		_gameIsActive = false;
	}
};

string Game::printLastTurn()
 {
	if(_turns.empty())
	{
		__throw_logic_error("didnt commit any turn now");
	}
	else
	{
		string s = (--_turns.end())->second;
		cout << s << endl;
	}
	return " ";
};
string Game::printStats()
{

	float p1Sg = _p1._statCardsGained;
	p1Sg = p1Sg / (_p1._statCardsGained +_p1._statCardsKept);
	p1Sg = p1Sg*100;

	float p2Sg = _p2._statCardsGained;
	p2Sg = p2Sg / (_p2._statCardsGained +_p2._statCardsKept);
	p2Sg = p2Sg*100;

	float p1sk = _p1._statCardsKept;
	p1sk = p1sk / 26;
	p1sk = p1sk*100;
	float p2sk = _p2._statCardsKept;
	p2sk = p2sk / 26;
	p2sk = p2sk*100;

	cout << "...PLAYER "+_p1._name +" STAT'S... " << endl;
	cout << "have overall "+to_string(_p1._statCardsGained +_p1._statCardsKept)+" cards with a 50 50 presentage of gaining" << endl;
	cout << "number of rounds is " + to_string(_turns.size())+" overall " << endl;
	cout << "gaind "+to_string(p1Sg) +"'%' of all of his card" << endl;
	cout << "kept "+to_string(p1sk) +"'%' of all of his start card (26 overall) " << endl;

	cout << "...PLAYER "+_p2._name +" STAT'S... " << endl;
	cout << "have overall "+to_string(_p2._statCardsGained +_p2._statCardsKept)+" with a 50 50 presentage of gaining"<< endl;
	cout << "number of rounds is " + to_string(_turns.size())+" overall "<< endl;
	cout << "gaind "+to_string(p2Sg) +"'%' of all of his card"<< endl;
	cout << "kept "+to_string(p2sk) +"'%' of all of his start card (26 overall) "<< endl;
	
	return "";
};

string Game::printLog()
{
	if(_turns.empty())
	{
		__throw_logic_error("didnt commit any turn now");
	}
	else
	{
		//map<string,string>::iterator a = _turns.begin();
		for(auto i = _turns.begin(); i != _turns.end(); i++)
		{
			cout << i->second << endl;
			//cout << "" << endl;
			//i++;
		}
	}
	return "true";
};

string Game::printWiner()
 {
	int p1 = 0;
	int p2 = 0;

	if(_turns.empty())
	{
		__throw_logic_error("didnt commit any turn now");
	}
	else
	{
		//map<string,string>::iterator a = _turns.begin();
		for(auto i = _turns.begin(); i != _turns.end(); i++)
		{
			if(i->first == _p1._name)
			{
				p1++;
			}
			else if (i->first == _p2._name)
			{
				p2++;
			}
		}

		if(p1>p2)
		{
			cout << "THE WINNER IS: "+_p1._name << endl;

		}
		else if(p1<p2)
		{
			cout << "THE WINNER IS: "+_p2._name << endl;
		}
		else
		{
			cout << "TIE " << endl;
		}

	}

	return "true";
};

void Game ::playAll()
{
     while(_gameIsActive)
	{
		playTurn();
	}
};