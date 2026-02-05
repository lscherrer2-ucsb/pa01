#include "game.h"
#include "card_list.h"

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
    for (auto it = bob_hand.rbegin(); it != bob_hand.rend(); ++it) {
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