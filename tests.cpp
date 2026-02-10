// tests.cpp
#include "card_list.h"
#include <iostream>
#include <sstream>

int test_count = 0;
int passed_count = 0;

void test(const std::string &name, bool condition) {
    test_count++;
    if (condition) {
        passed_count++;
        std::cout << "PASS: " << name << std::endl;
    } else {
        std::cout << "FAIL: " << name << std::endl;
    }
}

void test_insert() {
    CardList hand;
    Card c1(CLUBS, 5);
    Card c2(DIAMONDS, 3);
    Card c3(HEARTS, 8);

    test("Insert into empty tree", hand.insert(c1));
    test("Insert second card", hand.insert(c2));
    test("Insert third card", hand.insert(c3));
    test("Insert duplicate returns false", !hand.insert(c1));
    test(
        "All cards present after inserts",
        hand.contains(c1) && hand.contains(c2) && hand.contains(c3));
}

void test_remove() {
    CardList hand;
    Card c1(CLUBS, 5);
    Card c2(DIAMONDS, 3);
    Card c3(HEARTS, 8);

    test("Remove from empty tree returns false", !hand.remove(c1));

    hand.insert(c1);
    hand.insert(c2);
    hand.insert(c3);

    test("Remove existing card", hand.remove(c2));
    test("Card not present after remove", !hand.contains(c2));
    test("Other cards still present", hand.contains(c1) && hand.contains(c3));
    test("Remove non-existent card returns false", !hand.remove(c2));
}

void test_contains() {
    CardList hand;
    Card c1(CLUBS, 5);
    Card c2(DIAMONDS, 3);
    Card c3(HEARTS, 8);

    test("Contains on empty tree", !hand.contains(c1));

    hand.insert(c1);
    test("Contains after insert", hand.contains(c1));

    hand.insert(c2);
    hand.insert(c3);
    test(
        "Contains multiple cards",
        hand.contains(c1) && hand.contains(c2) && hand.contains(c3));

    hand.remove(c2);
    test("Contains returns false after remove", !hand.contains(c2));
    test(
        "Contains still finds remaining cards",
        hand.contains(c1) && hand.contains(c3));
}

void test_print() {
    CardList hand;
    Card c1(CLUBS, 5);
    Card c2(DIAMONDS, 3);
    Card c3(HEARTS, 8);

    std::ostringstream oss1;
    oss1 << hand;
    test("Print empty tree produces empty output", oss1.str().empty());

    hand.insert(c1);
    std::ostringstream oss2;
    oss2 << hand;
    test("Print single card works", oss2.str() == "c 5\n");

    hand.insert(c2);
    hand.insert(c3);
    std::ostringstream oss3;
    oss3 << hand;
    test("Print shows all cards", oss3.str() == "c 5\nd 3\nh 8\n");

    test("Print shows cards in order", true);

    hand.remove(c2);
    std::ostringstream oss4;
    oss4 << hand;
    test(
        "Print after remove shows remaining cards",
        oss4.str() == "c 5\nh 8\n");
}

void test_iterator() {
    CardList hand;
    Card c1(CLUBS, 3);
    Card c2(CLUBS, 5);
    Card c3(DIAMONDS, 2);

    test("Empty tree: begin() == end()", hand.begin() == hand.end());

    hand.insert(c1);
    auto it = hand.begin();
    test("Single node: begin() != end()", it != hand.end());

    hand.insert(c2);
    hand.insert(c3);

    it = hand.begin();
    Card first = *it;
    ++it;
    Card second = *it;
    ++it;
    Card third = *it;
    test(
        "Multiple nodes: forward traversal in order",
        first == c1 && second == c2 && third == c3);

    auto rit = hand.rbegin();
    Card rfirst = *rit;
    --rit;
    Card rsecond = *rit;
    test("Reverse traversal works", rfirst == c3 && rsecond == c2);

    auto it1 = hand.begin();
    auto it2 = hand.begin();
    test("Iterator comparison works", it1 == it2);
}

void test_playgame() {
    CardList alice1, bob1;
    Card c1(CLUBS, 5);
    Card c2(DIAMONDS, 7);
    Card c3(HEARTS, 10);

    alice1.insert(c1);
    alice1.insert(c2);
    bob1.insert(c2);
    bob1.insert(c3);

    std::ostringstream out1;
    std::streambuf *old = std::cout.rdbuf(out1.rdbuf());
    playGame(alice1, bob1);
    std::cout.rdbuf(old);

    test(
        "PlayGame removes common cards",
        alice1.contains(c1) && !alice1.contains(c2) && !bob1.contains(c2) &&
            bob1.contains(c3));

    CardList alice2, bob2;
    bob2.insert(c1);

    std::ostringstream out2;
    old = std::cout.rdbuf(out2.rdbuf());
    playGame(alice2, bob2);
    std::cout.rdbuf(old);

    test("PlayGame with empty hand terminates", bob2.contains(c1));

    CardList alice3, bob3;
    alice3.insert(c1);
    bob3.insert(c3);

    std::ostringstream out3;
    old = std::cout.rdbuf(out3.rdbuf());
    playGame(alice3, bob3);
    std::cout.rdbuf(old);

    test(
        "PlayGame with no common cards preserves all",
        alice3.contains(c1) && bob3.contains(c3));
}

int main() {
    std::cout << "Insert tests:" << std::endl;
    test_insert();

    std::cout << "\nRemove tests:" << std::endl;
    test_remove();

    std::cout << "\nContains tests:" << std::endl;
    test_contains();

    std::cout << "\nPrint tests:" << std::endl;
    test_print();

    std::cout << "\nIterator tests:" << std::endl;
    test_iterator();

    std::cout << "\nPlayGame tests:" << std::endl;
    test_playgame();

    std::cout << "\nResults: " << passed_count << "/" << test_count
              << " tests passed" << std::endl;

    if (passed_count == test_count) {
        return 0;
    } else {
        return 1;
    }
}
