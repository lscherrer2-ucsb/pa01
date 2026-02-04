// card.cpp
// Author: Your name
// Implementation of the classes defined in card.h
#include "card.h"
Card::Card(int suit, int rank) : suit(suit), rank(rank) {}
int Card::value(void) const {
    return (suit << 8 * sizeof(int) / 2) | rank;
}
bool operator<(Card l, Card r) {
    return l.value() < r.value();
}
bool operator>(Card l, Card r) {
    return l.value() > r.value();
}
bool operator<=(Card l, Card r) {
    return l.value() <= r.value();
}
bool operator>=(Card l, Card r) {
    return l.value() >= r.value();
}
bool operator==(Card l, Card r) {
    return l.value() == r.value();
}
bool operator!=(Card l, Card r) {
    return l.value() != r.value();
}
