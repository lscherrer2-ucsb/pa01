// card_list.h
// Author: Keegan Browne, Luke Scherrer
#ifndef CARD_LIST
#define CARD_LIST

#include "card.h"
#include <fstream>
class CardList {
  private:
    struct Node {
        Card card;
        Node *parent;
        Node *left;
        Node *right;

        Node(Card);
    };
    Node *root;

    struct Iterator {
        Node *current;

        Iterator(Node *n);
        const Card &operator*() const;
        Iterator &operator++();
        Iterator &operator--();
        bool operator==(const Iterator &other) const;
        bool operator!=(const Iterator &other) const;
    };

  public:
    CardList(void);
    ~CardList(void);
    CardList(const CardList &source);
    CardList &operator=(const CardList &source);

    bool insert(Card);
    bool remove(Card);
    bool contains(Card) const;

    Iterator begin(void);
    Iterator end(void);
    Iterator rbegin(void);
    Iterator rend(void);

  private:
    void clear(Node *n);
    Node *copySubtree(Node *n);
    Node *minNode(Node *root);
    Node *maxNode(Node *root);
    bool insertHelper(Node *, Card c);
    bool removeHelper(Node *, Card c);
};

std::ostream &operator<<(std::ostream &os, CardList &c);
CardList card_list_from_file(std::ifstream &file);
void playGame(CardList &alice_hand, CardList &bob_hand);

#endif
