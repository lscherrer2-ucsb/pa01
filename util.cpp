#include "util.h"
#include "card.h"
#include "card_list.h"
#include <cctype>
#include <cstddef>
#include <cstdlib>
#include <fstream>
#include <set>

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
CardList card_list_from_file(std::ifstream &file) {
    CardList hand;
    std::string line;
    while (getline(file, line) && (line.length() > 0)) {
        hand.insert(parse_card(line));
    };
    return hand;
}
std::set<Card> card_set_from_file(std::ifstream &file) {
    std::set<Card> hand;
    std::string line;
    while (getline(file, line) && (line.length() > 0)) {
        hand.insert(parse_card(line));
    };
    return hand;
}
