// card.h
// Author: Luke Scherrer
// All class declarations related to defining a single card go here
#ifndef CARD
#define CARD

#include <fstream>
#include <iostream>
#include <set>
#include <string>

enum Suit {
    CLUBS,
    DIAMONDS,
    SPADES,
    HEARTS,
};

struct Card {
    int suit;
    int rank;

    Card(int suit, int rank);
    int value(void) const;
};

bool operator<(Card, Card);
bool operator>(Card, Card);
bool operator<=(Card, Card);
bool operator>=(Card, Card);
bool operator==(Card, Card);
bool operator!=(Card, Card);

std::ostream &operator<<(std::ostream &os, Card c);

int parse_suit(char s);
int parse_rank(std::string s);
Card parse_card(std::string s);
std::set<Card> card_set_from_file(std::ifstream &file);
#endif
