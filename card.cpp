// card.cpp
// Author: Your name
// Implementation of the classes defined in card.h
#include "card.h"
#include <sstream>

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

std::ostream &operator<<(std::ostream &os, Card c) {
    std::string suit;
    switch (c.suit) {
    case Suit::HEARTS:
        suit = "h";
        break;
    case Suit::DIAMONDS:
        suit = "d";
        break;
    case Suit::SPADES:
        suit = "s";
        break;
    case Suit::CLUBS:
        suit = "c";
        break;
    default:
        break;
    }
    std::ostringstream oss;
    switch (c.rank) {
    case 1:
        oss << "a";
        break;
    case 11:
        oss << "j";
        break;
    case 12:
        oss << "q";
        break;
    case 13:
        oss << "k";
        break;
    default:
        oss << c.rank;
    }
    std::string rank = oss.str();
    return os << suit << " " << rank;
}