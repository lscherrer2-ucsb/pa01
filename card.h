// card.h
// Author: Luke Scherrer
// All class declarations related to defining a single card go here
#pragma once

#define MAX_RANK 13

enum Suit {
    CLUBS,
    DIAMONDS,
    SPADES,
    HEARTS,
};

enum Rank {
    ACE = 1,
    JACK = 11,
    QUEEN = 12,
    KING = 13,
};

struct Card {
    const Suit suit;
    const int rank;
    const int value;

    Card(Suit suit, int rank);
};
