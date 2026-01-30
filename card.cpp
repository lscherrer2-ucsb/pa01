// card.cpp
// Author: Luke Scherrer
// Implementation of the classes defined in card.h
#include "card.h"

Card::Card(Suit suit, int rank)
    : suit(suit), rank(rank), value(suit * (MAX_RANK + 1) + rank) {
}
