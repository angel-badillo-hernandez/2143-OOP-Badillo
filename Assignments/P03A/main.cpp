#include <iostream>
#include <fstream>
#include <string>
#include "emojis.h"

using namespace std;

struct Hands
{
    static string Rock()
    {
        return emojicpp::EMOJIS[":volcano:"];
    }
    static string Paper()
    {
        return emojicpp::EMOJIS[":page_with_curl:"];
    }
    static string Scissors()
    {
        return emojicpp::EMOJIS[":scissors:"];
    }
    static string Lizard()
    {
        return emojicpp::EMOJIS[":lizard:"];
    }
    static string Spock()
    {
        return emojicpp::EMOJIS[":raised_hand_with_part_between_middle_and_ring_fingers:"];
    }
};

int main()
{
    cout << Hands::Rock() << '\n';

    cout << Hands::Paper() << '\n';

    cout << Hands::Scissors() << '\n';

    cout << Hands::Lizard() << '\n';

    cout << Hands::Spock() << '\n';
}