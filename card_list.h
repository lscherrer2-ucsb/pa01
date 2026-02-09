// card_list.h
// Author: Your name
// All class declarations related to defining a BST that represents a player's
// hand
#ifndef CARD_LIST
#define CARD_LIST

#include "card.h"
#include <fstream>
#include <type_traits>
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

        Iterator(Node *n) : current(n) {}

        const Card &operator*() const {
            return current->card;
        }

        Iterator &operator++() {
            if (current->right) {
                current = current->right;
                while (current->left) current = current->left;
            } else {
                Node *p = current->parent;
                while (p && current == p->right) {
                    current = p;
                    p = p->parent;
                }
                current = p;
            }
            return *this;
        }

        bool operator!=(const Iterator &other) const {
            return current != other.current;
        }
    };
    struct ReverseIterator {
        Node *current;

        ReverseIterator(Node *n) : current(n) {}

        const Card &operator*() const {
            return current->card;
        }

        ReverseIterator &operator++() {
            if (current->left) {
                current = current->left;
                while (current->right) current = current->right;
            } else {
                Node *p = current->parent;
                while (p && current == p->left) {
                    current = p;
                    p = p->parent;
                }
                current = p;
            }
            return *this;
        }

        bool operator!=(const ReverseIterator &other) const {
            return current != other.current;
        }
    };

  public:
    CardList(void);
    ~CardList(void);
    CardList(const CardList &source);
    CardList &operator=(const CardList &source);

    bool insert(Card);
    bool remove(Card);
    bool contains(Card) const;
    Card min(void);
    Card max(void);

    Iterator begin(void);
    Iterator end(void);
    ReverseIterator rbegin(void);
    ReverseIterator rend(void);

  private:
    void clear(Node *n);
    Node *copySubtree(Node *n);
    Node *successorNode(Node *);
    Node *predecessorNode(Node *);
    Node *minNode(Node *root);
    Node *maxNode(Node *root);
    bool insertHelper(Node *, Card c);
    bool removeHelper(Node *, Card c);
};

std::ostream &operator<<(std::ostream &os, CardList &c);
CardList card_list_from_file(std::ifstream &file);

#endif
