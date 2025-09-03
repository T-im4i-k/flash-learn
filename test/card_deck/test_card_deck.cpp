#include <cassert>

#include "card_deck/deck.hpp"

int main() {
    // Test Card
    {
        Core::Card card1 = {1, "question?", "answer!"};
        assert(card1.id() == 1);
        assert(card1.front() == "question?");
        assert(card1.back() == "answer!");
        card1.front() = "new question?";
        assert(card1.front() == "new question?");
        card1.back() = "new answer!";
        assert(card1.back() == "new answer!");
    }
    return 0;
}
