#include "game_set.h"
#include "card.h"
#include <iostream>
#include <set>

bool take_turn(std::set<Card> &alice_hand, std::set<Card> &bob_hand) {
    bool done = true;
    for (auto it = alice_hand.begin(); it != alice_hand.end(); ++it) {
        Card c = *it;
        auto bobIt = bob_hand.find(c);
        if (*bobIt == *it) {
            std::cout << "Alice picked matching card " << c << std::endl;
            bob_hand.erase(bobIt);
            alice_hand.erase(it);
            done = false;
        }
    }
    for (auto it = bob_hand.rbegin(); it != bob_hand.rend(); ++it) {
        Card c = *it;
        auto aliceIt = alice_hand.find(c);
        if (*aliceIt == *it) {
            std::cout << "Bob picked matching card " << c << std::endl;
            bob_hand.erase(bob_hand.find(c));
            alice_hand.erase(aliceIt);
            done = false;
        }
    }
    return done;
}