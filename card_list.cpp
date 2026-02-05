// card_list.cpp
// Author: Your name
// Implementation of the classes defined in card_list.h
CardList::CardList(void) {
    root = nullptr;
}
CardList::~CardList(void) {
    clear(root);
}
CardList::CardList(const CardList& source) {
    root = copySubtree(source.root);
}
CardList::CardList& CardList::operator=(const CardList& source) {
    clear(root);
    root = copySubtree(source.root)
}

// Helper function for destructor
void CardList::clear(Node *n) {
    if(n != nullptr) {
        clear(n->left);
        clear(n->right);
    }
    delete n;
}

// Helper function for copy constructor
Node* copySubtree(Node *n) {
    if(n == nullptr) return nullptr;
    copySubtree(n->left);
    Node* newNode = new Node();
    newNode->card = n->card;
    copySubtree(n->right);
    return newNode;
} 
