#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <functional>
#include <random>
using namespace std;

#define ROCK u8"\U0001F5FB"
#define PAPER u8"\U0001F4C3"
#define SCISSORS u8"\U0001F52A"
#define LIZARD u8"\U0001F98E"
#define SPOCK u8"\U0001F596"

/**
 * Hands
 * 
 * Description:
 *      A struct containing all the hands for Rock Papr Scissors Lizard Spock
 * 
 * Public Methods:
 *  static string RandHand()
 *  static string Rock()
 *  static string Paper()
 *  static string Scissors()
 *  static string Lizard()
 *  static string Spock()
 *                
 * 
 * Private Methods:
 *      - None
 * 
 * Usage: 
 * 
 *      RandHand();   // Returns a random hand
 *      Rock();       // Returns rock emoji
 *      Paper();      // Returns paper emoji
 *      Scissors();   // Returns scissors emoji
 *      Lizard();     // Returns lizard emoji
 *      Spock();      // Returns spock emoji
 *       
 */
struct Hands
{

    static map<string, string> Emojis;
    static map<string, string> Names;

    static string RandHand()
    {
        auto it = Emojis.begin(); // iterator to front of map

        std::advance(it, rand() % Emojis.size()); // advance some random amnt
                                                  //   of steps

        string random_hand = it->second; // grab emoji from map

        return random_hand; // return rand emoji
    }

    static string Rock()
    {
        return Emojis["rock"];
    }

    static string Paper()
    {
        return Emojis["paper"];
    }

    static string Scissors()
    {
        return Emojis["scissors"];
    }

    static string Lizard()
    {
        return Emojis["lizard"];
    }

    static string Spock()
    {
        return Emojis["spock"];
    }

    
};

map<string, string> Hands::Emojis = {
    {"rock", ROCK},
    {"paper", PAPER},
    {"scissors", SCISSORS},
    {"lizard", LIZARD},
    {"spock", SPOCK}};

map<string, string> Hands::Names = {
    {ROCK, "rock"},
    {PAPER, "paper"},
    {SCISSORS, "scissors"},
    {LIZARD, "lizard"},
    {SPOCK, "spock"}};

/**
 * Player
 * 
 * Description:
 *      A struct containg two weapons (hands) which are of type string
 * 
 * Public Methods:
 *                Player()
 *                
 * 
 * Private Methods:
 *      - None
 * 
 * Usage: 
 * 
 *      Player p1; // Creates instance of a player with 2 random hands
 *       
 */

struct Player
{
    string weapon1;
    string weapon2;

    /**
     * Constructor guarantees a player has two different "weapons"
     */
    Player()
    {
        weapon1 = Hands::RandHand();
        weapon2 = Hands::RandHand();

        while (weapon2 == weapon1)
        {
            weapon2 = Hands::RandHand();
        }
    }

    Player(string weapon1, string weapon2)
    {
        this->weapon1 = weapon1;
        this->weapon2 = weapon2;
    }

    bool rockVS(string other)
    {
        bool win = false;

        if (other == PAPER)
        {
            win = false; // Gets covered
        }
        else if (other == SCISSORS)
        {
            win = true; // Crushes scissors
        }
        else if (other == LIZARD)
        {
            win = true; // Crushes lizard
        }
        else if (other == SPOCK)
        {
            win = false; // Gets vaporized
        }
        return win;
    }

    bool paperVS(string other)
    {
        bool win = false;

        if (other == ROCK)
        {
            win = true; // Covers rock
        }
        else if (other == SCISSORS)
        {
            win = false; // Gets cut
        }
        else if (other == LIZARD)
        {
            win == false; // Gets eaten
        }
        else if (other == SPOCK)
        {
            win = true; // Disproves Spock
        }
        return win;
    }

    bool scissorsVS(string other)
    {
        bool win = false;

        if (other == ROCK)
        {
            win = false; // Gets crushed
        }
        else if (other == PAPER)
        {
            win = true; // Cuts paper
        }
        else if (other == LIZARD)
        {
            win = true; // Decapitates lizard
        }
        else if (other == SPOCK)
        {
            win == false; // Gets smashed
        }
        return win;
    }

    bool lizardVS(string other)
    {
        bool win = false;

        if (other == ROCK)
        {
            win = false; // Gets crushed
        }
        else if (other == PAPER)
        {
            win = true; // Eats paper
        }
        else if (other == SCISSORS)
        {
            win = false; // Gets decapitated
        }
        else if (other == SPOCK)
        {
            win == true; // Poisons Spock
        }
        return win;
    }

    bool spockVS(string other)
    {
        bool win = false;

        if (other == ROCK)
        {
            win = true; // Vaporizes rock
        }
        else if (other == PAPER)
        {
            win == false; // Gets disproved
        }
        else if (other == SCISSORS)
        {
            win == true; // Smashes scissors
        }
        else if (other == LIZARD)
        {
            win = false; // Gets poisoned
        }
        return win;
    }

    bool operator==(Player &other)
    {
        return (this->weapon1 == other.weapon1) && (this->weapon2 == other.weapon2);
    }

    virtual bool operator>(Player &other)
    {
        bool result = false;

        if (*this == other) // Players have all same weapons
        {
            result = false;
        }
        else if (this->weapon1 == other.weapon1) // Players have same 1st weapons
        {
            if (this->weapon2 == ROCK)
            {
                result = rockVS(other.weapon2);
            }
            else if (this->weapon2 == PAPER)
            {
                result = paperVS(other.weapon2);
            }
            else if (this->weapon2 == SCISSORS)
            {
                result = scissorsVS(other.weapon2);
            }
            else if (this->weapon2 == LIZARD)
            {
                result = lizardVS(other.weapon2);
            }
            else
            {
                result = spockVS(other.weapon2);
            }
        }
        else
        {
            if (this->weapon1 == ROCK)
            {
                result = rockVS(other.weapon1);
            }
            else if (this->weapon1 == PAPER)
            {
                result = paperVS(other.weapon1);
            }
            else if (this->weapon1 == SCISSORS)
            {
                result = scissorsVS(other.weapon1);
            }
            else if (this->weapon1 == LIZARD)
            {
                result = lizardVS(other.weapon1);
            }
            else
            {
                result = spockVS(other.weapon1);
            }
        }
        return result;
    }

    bool operator<(Player &other)
    {
        bool result = false;

        if (*this == other) // Players have all same weapons
        {
            result = false;
        }
        else // Opposite of >
        {
            result = !(*this > other);
        }
        return result;
    }
};

void battle(Player p1, Player p2)
{
    if(p1 > p2)
    {
        if(p1.weapon1 != p2.weapon1)
        {
            cout << "Player 1's " << p1.weapon1 << " beat Player 2's " << p2.weapon1 << "\n\n";
        }
        else
        {
            cout << "Player 1's " << p1.weapon2 << " beat Player 2's " << p2.weapon2 << "\n\n";
        }
    }
    else if(p1 < p2)
    {
         if(p1.weapon1 != p2.weapon1)
        {
            cout << "Player 2's " << p2.weapon1 << " beat Player 1's " << p1.weapon1 << "\n\n";
        }
        else
        {
            cout << "Player 2's " << p2.weapon2 << " beat Player 1's " << p1.weapon2 << "\n\n";
        }
    }
    else
    {
        cout << "It's a tie!" << '\n';
        cout << "Player 1's weapons: " << p1.weapon1 << " " << p1.weapon2 << '\n';
        cout << "Player 2's weapons: " << p2.weapon1 << " " << p2.weapon2 << "\n\n";
    }
}