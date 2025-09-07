#include "db/core/db_manager.hpp"
#include "db/core/schema_initializer.hpp"
#include "db/repository/card_repository.hpp"
#include "db/repository/deck_repository.hpp"

#include <QCoreApplication>
#include <cassert>
#include <queue>

namespace TestUtils {
    bool cardEqual(const Core::Card &lhs, const Core::Card &rhs) {
        return lhs.id() == rhs.id() && lhs.front() == rhs.front() &&
               lhs.back() == rhs.back();
    }

    bool deckEqual(const Core::Deck &lhs, const Core::Deck &rhs) {
        const auto expectedSize = lhs.cardVector().size();

        for (size_t i = 0; i < expectedSize; i++) {
            if (cardEqual(lhs.cardVector()[i], rhs.cardVector()[i]))
                return false;
        }

        return true;
    }
} // namespace TestUtils

int main(int argc, char **argv) {
    QCoreApplication app(argc, argv);

    DB::DBManager::open(":memory:");
    DB::SchemaInitializer::initialize();

    // Add & Select tests

    int deck1 = DB::DeckRepository::addDeck("Spanish A2");

    assert(DB::CardRepository::addCard(deck1, "aburrido", "boring"));
    assert(DB::CardRepository::addCard(deck1, "salsa", "sauce"));
    assert(DB::CardRepository::addCard(deck1, "sombrero", "hat"));

    Core::Deck result(deck1, "", "",
                      {Core::Card(-1, "aburrido", "boring"),
                       Core::Card(-1, "salsa", "sauce"),
                       Core::Card(-1, "sombrero", "hat")});

    Core::Deck response(deck1, "", "");
    DB::CardRepository::selectCardsByDeck(response);

    assert(TestUtils::deckEqual(result, response));

    int deck2 = DB::DeckRepository::addDeck("Czech A1");

    assert(DB::CardRepository::addCard(deck2, "taska", "bag"));
    int toDel = DB::CardRepository::addCard(deck2, "dzus", "juice");
    assert(DB::CardRepository::addCard(deck2, "stul", "table"));
    int toDel2 = DB::CardRepository::addCard(deck2, "obchod", "shop");
    assert(DB::CardRepository::addCard(deck2, "kniha", "book"));

    Core::Deck result2(deck2, "", "",
                       {
                           Core::Card(-1, "taska", "bag"),
                           Core::Card(-1, "dzus", "juice"),
                           Core::Card(-1, "stul", "table"),
                           Core::Card(-1, "obchod", "shop"),
                           Core::Card(-1, "kniha", "book"),

                       });

    Core::Deck response2(deck2, "", "");
    DB::CardRepository::selectCardsByDeck(response2);

    assert(TestUtils::deckEqual(result2, response2));

    // Removing test

    assert(DB::CardRepository::removeCard(deck2, toDel));
    assert(DB::CardRepository::removeCard(deck2, toDel2));

    Core::Deck result3(deck2, "", "",
                       {
                           Core::Card(-1, "taska", "bag"),
                           Core::Card(-1, "stul", "table"),
                           Core::Card(-1, "kniha", "book"),
                       });

    DB::CardRepository::selectCardsByDeck(response2);

    assert(TestUtils::deckEqual(result3, response2));

    return 0;
}