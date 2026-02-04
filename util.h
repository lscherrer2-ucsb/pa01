#pragma once
#include "card.h"
#include "card_list.h"
#include <set>
#include <string>

Card parse_card(std::string s);
CardList card_list_from_file(std::ifstream &file);
std::set<Card> card_set_from_file(std::ifstream &file);
