#pragma once

#include "card.h"
#include <set>

bool take_turn(std::set<Card> &alice_hand, std::set<Card> &bob_hand);
