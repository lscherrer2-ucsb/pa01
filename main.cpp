// This file should implement the game using a custom implementation of a BST
// (based on your earlier BST implementation)
// Do not include set in this file
#include "card_list.h"
#include <fstream>
#include <iostream>

using namespace std;

bool take_turn(CardList &alice_hand, CardList &bob_hand);

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

    CardList alice_hand = card_list_from_file(alice_file);
    CardList bob_hand = card_list_from_file(bob_file);

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
bool take_turn(CardList &alice_hand, CardList &bob_hand) {
    bool done = true;
    for (auto it = alice_hand.begin(); it != alice_hand.end(); ++it) {
        Card c = *it;
        if (bob_hand.contains(c)) {
            std::cout << "Alice picked matching card " << c << std::endl;
            bob_hand.remove(c);
            alice_hand.remove(c);
            done = false;
            break;
        }
    }
    for (auto it = bob_hand.rbegin(); it != bob_hand.rend(); --it) {
        Card c = *it;
        if (alice_hand.contains(c)) {
            std::cout << "Bob picked matching card " << c << std::endl;
            bob_hand.remove(c);
            alice_hand.remove(c);
            done = false;
            break;
        }
    }
    return done;
}
