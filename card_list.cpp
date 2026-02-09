// card_list.cpp
// Author: Your name
// Implementation of the classes defined in card_list.h
#include "card_list.h"
#include <iostream>
CardList::CardList(void) {
    root = nullptr;
}
CardList::~CardList(void) {
    clear(root);
}
CardList::CardList(const CardList &source) {
    root = copySubtree(source.root);
}
CardList &CardList::operator=(const CardList &source) {
    clear(root);
    root = copySubtree(source.root);
    return *this;
}

void CardList::clear(Node *n) {
    if (n != nullptr) {
        clear(n->left);
        clear(n->right);
    }
    delete n;
}

CardList::Node *CardList::copySubtree(Node *n) {
    if (n == nullptr) return nullptr;
    copySubtree(n->left);
    Node *newNode = new Node(n->card);
    newNode->card = n->card;
    copySubtree(n->right);
    return newNode;
}

CardList::Node::Node(Card c)
    : card(c), parent(nullptr), left(nullptr), right(nullptr) {}
Card CardList::min() {
    return minNode(root)->card;
}
Card CardList::max() {
    return maxNode(root)->card;
}
CardList::Node *CardList::minNode(Node *root) {
    return root->left ? minNode(root->left) : root;
}
CardList::Node *CardList::maxNode(Node *root) {
    return root->right ? maxNode(root->right) : root;
}
bool CardList::contains(Card c) const {
    Node *n = root;
    while (n) {
        if (c.value() < n->card.value())
            n = n->left;
        else if (c.value() > n->card.value())
            n = n->right;
        else
            return true;
    }
    return false;
}
bool CardList::remove(Card c) {
    return removeHelper(root, c);
}
bool CardList::insert(Card c) {
    if (!root) {
        root = new Node(c);
        return true;
    }
    return insertHelper(root, c);
}
bool CardList::insertHelper(Node *n, Card c) {
    if (c.value() < n->card.value()) {
        if (!n->left) {
            Node *newNode = new Node(c);
            n->left = newNode;
            newNode->parent = n;
            return true;
        } else {
            return insertHelper(n->left, c);
        }
    } else if (c.value() > n->card.value()) {
        if (!n->right) {
            Node *newNode = new Node(c);
            n->right = newNode;
            newNode->parent = n;
            return true;
        } else {
            return insertHelper(n->right, c);
        }
    } else {
        return false;
    }
}
bool CardList::removeHelper(Node *n, Card c) {
    if (!n) return false;

    if (c.value() < n->card.value()) {
        return removeHelper(n->left, c);
    }
    if (c.value() > n->card.value()) {
        return removeHelper(n->right, c);
    }

    if (!n->left && !n->right) {
        if (n->parent) {
            if (n->parent->left == n)
                n->parent->left = nullptr;
            else
                n->parent->right = nullptr;
        } else {
            root = nullptr;
        }
        delete n;
    } else if (!n->left) {
        if (n->parent) {
            if (n->parent->left == n)
                n->parent->left = n->right;
            else
                n->parent->right = n->right;
        } else {
            root = n->right;
        }
        n->right->parent = n->parent;
        delete n;
    } else if (!n->right) {
        if (n->parent) {
            if (n->parent->left == n)
                n->parent->left = n->left;
            else
                n->parent->right = n->left;
        } else {
            root = n->left;
        }
        n->left->parent = n->parent;
        delete n;
    } else {
        Node *successor = minNode(n->right);
        n->card = successor->card;
        return removeHelper(successor, successor->card);
    }

    return true;
}

CardList::Iterator CardList::begin() {
    return Iterator(root ? minNode(root) : nullptr);
}
CardList::Iterator CardList::end() {
    return Iterator(nullptr);
}
CardList::ReverseIterator CardList::rbegin() {
    return ReverseIterator(root ? maxNode(root) : nullptr);
}
CardList::ReverseIterator CardList::rend() {
    return ReverseIterator(nullptr);
}

CardList::Node *CardList::successorNode(Node *n) {
    if (!n) return nullptr;
    if (n->right) return minNode(n->right);
    Node *p = n->parent;
    while (p && n == p->right) {
        n = p;
        p = p->parent;
    }
    return p;
}

CardList::Node *CardList::predecessorNode(Node *n) {
    if (!n) return nullptr;
    if (n->left) return maxNode(n->left);
    Node *p = n->parent;
    while (p && n == p->left) {
        n = p;
        p = p->parent;
    }
    return p;
}

std::ostream &operator<<(std::ostream &os, CardList &c) {
    for (auto it = c.begin(); it != c.end(); ++it)
        std::cout << *it << std::endl;
    return os;
}

CardList card_list_from_file(std::ifstream &file) {
    CardList hand;
    std::string line;
    while (getline(file, line) && (line.length() > 0)) {
        hand.insert(parse_card(line));
    }
    return hand;
}