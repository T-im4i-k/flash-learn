#include <array>
#include <cassert>

#include "card_deck/deck.hpp"

namespace TestUtils {
    bool cardEqual(const Core::Card &lhs, const Core::Card &rhs) {
        return lhs.id() == rhs.id() && lhs.front() == rhs.front() &&
               lhs.back() == rhs.back();
    }
} // namespace TestUtils


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
    // Test Deck
    {
        Core::Deck deck = {1, "title", "description"};
        assert(deck.id() == 1);
        assert(deck.title() == "title");
        assert(deck.description() == "description");

        const std::array card_vec = {Core::Card{1, "front1", "back1"},
                                     Core::Card{2, "front2", "back2"},
                                     Core::Card{3, "front3", "back3"}};
        assert(deck.cardVector().empty());
        for (const Core::Card &card: card_vec) {
            deck.cardVector().push_back(card);
            assert(TestUtils::cardEqual(deck.cardVector().back(), card));
        }
        assert(deck.cardVector().size() == 3);
        assert(deck.cardVector()[1].id() == 2);

        deck.shuffle();
    }
    return 0;
}
