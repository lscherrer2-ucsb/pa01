// This file should implement the game using the std::set container class
// Do not include card_list.h in this file
#include "card.h"
#include <fstream>
#include <iostream>
#include <set>

using namespace std;

std::ostream &operator<<(std::ostream &os, std::set<Card> &c);
bool take_turn(std::set<Card> &alice_hand, std::set<Card> &bob_hand);

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

bool take_turn(std::set<Card> &alice_hand, std::set<Card> &bob_hand) {
    bool done = true;
    for (auto it = alice_hand.begin(); it != alice_hand.end(); ++it) {
        Card c = *it;
        auto bobIt = bob_hand.find(c);
        if (bobIt != bob_hand.end()) {
            std::cout << "Alice picked matching card " << c << std::endl;
            bob_hand.erase(bobIt);
            alice_hand.erase(it);
            done = false;
            break;
        }
    }
    for (auto it = bob_hand.rbegin(); it != bob_hand.rend(); ++it) {
        Card c = *it;
        auto aliceIt = alice_hand.find(c);
        if (aliceIt != alice_hand.end()) {
            std::cout << "Bob picked matching card " << c << std::endl;
            bob_hand.erase(bob_hand.find(c));
            alice_hand.erase(aliceIt);
            done = false;
            break;
        }
    }
    return done;
}

std::ostream &operator<<(std::ostream &os, std::set<Card> &c) {
    for (auto it = c.begin(); it != c.end(); ++it)
        std::cout << *it << std::endl;
    return os;
}
