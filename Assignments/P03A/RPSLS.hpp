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
#define LIZARD u8"\U0001F438"
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
    static map<string, string> Emojis; // Name : Emojis
    static map<string, string> Names;  // Emojis : Names

    /**
     * Public: RandHand
     * 
     * Description:
     *      Returns a random emoji for rpsls
     * 
     * Params:
     *      None
     * 
     * Returns:
     *      string random_hand, a random emoji
     */
    static string RandHand()
    {
        auto it = Emojis.begin(); // iterator to front of map

        std::advance(it, rand() % Emojis.size()); // advance some random amnt
                                                  //   of steps

        string random_hand = it->second; // grab emoji from map

        return random_hand; // return rand emoji
    }

    /**
     * Public: Rock
     * 
     * Description:
     *      Returns rock emoji
     * 
     * Params:
     *      None
     * 
     * Returns:
     *      string, being the rock emoji
     */
    static string Rock()
    {
        return Emojis["rock"];
    }

    /**
     * Public: Paper
     * 
     * Description:
     *      Returns paper emoji
     * 
     * Params:
     *      None
     * 
     * Returns:
     *      string, being the paper emoji
     */
    static string Paper()
    {
        return Emojis["paper"];
    }

    /**
     * Public: Scissors
     * 
     * Description:
     *      Returns scissors emoji
     * 
     * Params:
     *      None
     * 
     * Returns:
     *      string, being the scissors emoji
     */
    static string Scissors()
    {
        return Emojis["scissors"];
    }

    /**
     * Public: Lizard
     * 
     * Description:
     *      Returns lizard emoji
     * 
     * Params:
     *      None
     * 
     * Returns:
     *      string, being the lizard emoji
     */
    static string Lizard()
    {
        return Emojis["lizard"];
    }

    /**
     * Public: Spock
     * 
     * Description:
     *      Returns spock emoji
     * 
     * Params:
     *      None
     * 
     * Returns:
     *      string, being the spock emoji
     */
    static string Spock()
    {
        return Emojis["spock"];
    }
};

// Map of Names : Emojis
map<string, string> Hands::Emojis = {
    {"rock", ROCK},
    {"paper", PAPER},
    {"scissors", SCISSORS},
    {"lizard", LIZARD},
    {"spock", SPOCK}};

// Map of Emojis : Names
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
 *           bool rockVS(string other)
 *           bool paperVS(string other)
 *           bool scissorsVS(string other)
 *           bool lizardVS(string other)
 *           bool spockVS(string other)
 *           bool operator==(Player& other)
 *           bool operator>(Player& other)
 *           bool operator<(Player& other)
 * Private Methods:
 *      - None
 * 
 * Usage: 
 * 
 *      Player p1; // Creates instance of a player with 2 random hands
 *      Player p2; // same
 *      bool rockVS(p2.weapon1); returns true if weapon beats rock, false otherwise
 *      ... Same with other bool ...vs(string other) functions 
 *      bool result = p1 > p2; True if p1 beats p2
 *      bool result = p1 < p2; True if p1 loses
 *      bool result = p1 == p2; True if tied
 */
struct Player
{
private:
    /**
     * Private: rockVS
     * 
     * Description:
     *      Returns outcome of rock vs other hand
     * 
     * Params:
     *      string other, other hand emoji
     * 
     * Returns:
     *      bool result, true if rock wins, false is loss
     */
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

    /**
     * Private: paperVS
     * 
     * Description:
     *      Returns outcome of paper vs other hand
     * 
     * Params:
     *      string other, other hand emoji
     * 
     * Returns:
     *      bool result, true if paper wins, false is loss
     */
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

    /**
     * Private: scissorsVS
     * 
     * Description:
     *      Returns outcome of scissors vs other hand
     * 
     * Params:
     *      string other, other hand emoji
     * 
     * Returns:
     *      bool result, true if scissors wins, false is loss
     */
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

    /**
     * Private: lizardVS
     * 
     * Description:
     *      Returns outcome of lizard vs other hand
     * 
     * Params:
     *      string other, other hand emoji
     * 
     * Returns:
     *      bool result, true if lizard wins, false is loss
     */
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

    /**
     * Private: spockVS
     * 
     * Description:
     *      Returns outcome of spock vs other hand
     * 
     * Params:
     *      string other, other hand emoji
     * 
     * Returns:
     *      bool result, true if spock wins, false is loss
     */
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

public:
    string weapon1; // A hand emoji
    string weapon2; // Another hand emoji

    /**
     * Public: Player
     * 
     * Description:
     *      Constructs a player with random weapons
     * 
     * Params:
     *      None
     * 
     * Returns:
     *      Nothing
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

    /**
     * Public: operator==
     * 
     * Description:
     *      Returns outcome of p1 == p2
     * 
     * Params:
     *      Player &other, other player
     * 
     * Returns:
     *      bool result, true if p1 has same weapons as p2, meaning they tied
     */
    bool operator==(Player &other)
    {
        return (this->weapon1 == other.weapon1) && (this->weapon2 == other.weapon2);
    }

    /**
     * Public: operator>
     * 
     * Description:
     *      Returns outcome of p1 > p2
     * 
     * Params:
     *      Player &other, other player
     * 
     * Returns:
     *      bool result, true if p1 beats p2, false otherwise
     */
    bool operator>(Player &other)
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

    /**
     * Public: operator<
     * 
     * Description:
     *      Returns outcome of p1 < p2
     * 
     * Params:
     *      Player &other
     * 
     * Returns:
     *      bool result, true if p1 loses to p2, false otherwise
     */
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

/**
 * Public: battle
 * 
 * Description:
 *      Prints outcome of battle to standard output
 * 
 * Params:
 *      ostream &os, (cout typically)
 *      Player p1, player 1
 *      Player p2, player 2
 * 
 * Returns:
 *      None, just prints out result of battle to standard output
 */
void battle(ostream &os, Player p1, Player p2)
{
    if (p1 > p2)
    {
        if (p1.weapon1 != p2.weapon1)
        {
            os << "Player 1's " << p1.weapon1 << " beat Player 2's " << p2.weapon1 << "\n\n";
        }
        else
        {
            os << "Player 1's " << p1.weapon2 << " beat Player 2's " << p2.weapon2 << "\n\n";
        }
    }
    else if (p1 < p2)
    {
        if (p1.weapon1 != p2.weapon1)
        {
            os << "Player 2's " << p2.weapon1 << " beat Player 1's " << p1.weapon1 << "\n\n";
        }
        else
        {
            os << "Player 2's " << p2.weapon2 << " beat Player 1's " << p1.weapon2 << "\n\n";
        }
    }
    else
    {
        os << "It's a tie!" << '\n';
        os << "Player 1's weapons: " << p1.weapon1 << " " << p1.weapon2 << '\n';
        os << "Player 2's weapons: " << p2.weapon1 << " " << p2.weapon2 << "\n\n";
    }
}

/**
 * Public: battle
 * 
 * Description:
 *      Prints outcome of battle to output file stream
 * 
 * Params:
 *      oftream &of, output file stream
 *      Player p1, player 1
 *      Player p2, player 2
 * 
 * Returns:
 *      None, just prints out result of battle to output file
 */
void battle(ofstream &of, Player p1, Player p2)
{
    if (p1 > p2)
    {
        if (p1.weapon1 != p2.weapon1)
        {
            of << "Player 1's " << p1.weapon1 << " beat Player 2's " << p2.weapon1 << "\n\n";
        }
        else
        {
            of << "Player 1's " << p1.weapon2 << " beat Player 2's " << p2.weapon2 << "\n\n";
        }
    }
    else if (p1 < p2)
    {
        if (p1.weapon1 != p2.weapon1)
        {
            of << "Player 2's " << p2.weapon1 << " beat Player 1's " << p1.weapon1 << "\n\n";
        }
        else
        {
            of << "Player 2's " << p2.weapon2 << " beat Player 1's " << p1.weapon2 << "\n\n";
        }
    }
    else
    {
        of << "It's a tie!" << '\n';
        of << "Player 1's weapons: " << p1.weapon1 << " " << p1.weapon2 << '\n';
        of << "Player 2's weapons: " << p2.weapon1 << " " << p2.weapon2 << "\n\n";
    }
}
