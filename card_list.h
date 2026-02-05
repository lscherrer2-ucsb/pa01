// card_list.h
// Author: Your name
// All class declarations related to defining a BST that represents a player's
// hand
#pragma once

#include "card.h"
class CardList {
  private:
    struct Node {
        Card card;
        Node *parent;
        Node *left;
        Node *right;
    };
    Node *root;

  public:
    CardList(void);
    ~CardList(void);
    CardList(const CardList& source);
    CardList& operator=(const CardList& source);

    bool insert(Card);
    bool remove(Card);
    Card successor(Card);
    Card predecessor(Card);
    Card min(void);
    Card max(void);

  private:
    void clear(Node *n); // helper for destructor
    Node *successorNode(Node *);
    Node *predecessorNode(Node *);
    Node *minNode(Node *root);
    Node *maxNode(Node *root);
    bool insertHelper(Node *, Card c);
    bool removeHelper(Node *, Card c);
};
