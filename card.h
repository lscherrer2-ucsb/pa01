// card.h
// Author: Your name
// All class declarations related to defining a single card go here
#pragma once

enum Suit {
    HEARTS,
    SPADES,
    DIAMONDS,
    CLUBS,
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
