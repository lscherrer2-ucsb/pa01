// card.cpp
// Author: Luke Scherrer
#include "card.h"
#include <cctype>
#include <set>
#include <sstream>
#include <string>
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

int parse_suit(char s) {
    switch (s) {
    case 'c':
        return Suit::CLUBS;
    case 's':
        return Suit::SPADES;
    case 'h':
        return Suit::HEARTS;
    case 'd':
        return Suit::DIAMONDS;
    }
    return -1;
}

int parse_rank(std::string s) {
    if (s.size() > 1) {
        return 10;
    }
    char c_rank = s[0];
    if (std::isalpha(c_rank)) {
        switch (c_rank) {
        case 'a':
            return 1;
        case 'j':
            return 11;
        case 'q':
            return 12;
        case 'k':
            return 13;
        }
    }
    return c_rank - '0';
}

Card parse_card(std::string s) {
    char c_suit = s[0];
    std::string s_rank(s.begin() + 2, s.end());
    return Card(parse_suit(c_suit), parse_rank(s_rank));
}

std::set<Card> card_set_from_file(std::ifstream &file) {
    std::set<Card> hand;
    std::string line;
    while (getline(file, line) && (line.length() > 0)) {
        hand.insert(parse_card(line));
    }
    return hand;
}
