// This file should implement the game using the std::set container class
// Do not include card_list.h in this file
#include "card.h"
#include "game_set.h"
#include "util.h"
#include <fstream>
#include <iostream>
#include <set>

using namespace std;

std::ostream &operator<<(std::ostream &os, std::set<Card> &c) {
    for (auto it = c.begin(); it != c.end(); ++it)
        std::cout << *it << std::endl;
    return os;
}

int main(int argv, char **argc) {
    if (argv < 3) {
        cout << "Please provide 2 file names" << endl;
        return 1;
    }

    ifstream alice_file(argc[1]);
    ifstream bob_file(argc[2]);

    if (alice_file.fail() || bob_file.fail()) {
        cout << "Could not open file " << argc[2];
        return 1;
    }

    std::set<Card> alice_hand = card_set_from_file(alice_file);
    std::set<Card> bob_hand = card_set_from_file(bob_file);

    alice_file.close();
    bob_file.close();

    bool done = false;
    while (!done) done = take_turn(alice_hand, bob_hand);

    std::cout << std::endl;

    std::cout << "Alice's cards:" << std::endl;
    std::cout << alice_hand << std::endl;

    std::cout << "Bob's cards:" << std::endl;
    std::cout << bob_hand;

    return 0;
}
