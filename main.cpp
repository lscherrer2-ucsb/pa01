// This file should implement the game using a custom implementation of a BST
// (based on your earlier BST implementation)
#include "card.h"
#include "card_list.h"
#include "util.h"
#include <fstream>
#include <iostream>
#include <string>
// Do not include set in this file

using namespace std;

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

    return 0;
}
