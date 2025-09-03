#include <QCoreApplication>
#include <cassert>
#include <iostream>
#include <queue>

#include "db/core/db_manager.hpp"
#include "db/core/schema_initializer.hpp"
#include "db/repository/card_repository.hpp"
#include "db/repository/deck_repository.hpp"

int main(int argc, char **argv) {

    QCoreApplication app(argc, argv);

    DB::DBManager::open(":memory:");
    DB::SchemaInitializer::initialize();

    int deck1 = DB::DeckRepository::addDeck("Spanish A2");

    assert(DB::CardRepository::addCard(deck1, "aburrido", "boring"));
    assert(DB::CardRepository::addCard(deck1, "salsa", "sauce"));
    assert(DB::CardRepository::addCard(deck1, "sombrero", "hat"));

    std::queue<std::string> result;
    result.emplace("aburrido");
    result.emplace("salsa");
    result.emplace("sombrero");


    Core::Deck response(deck1, "", "");
    DB::CardRepository::selectCardsByDeck(response);

    assert(!response.cardVector().empty());

    for (const auto& card : response.cardVector()) {
        assert(card.front() == result.front());
        result.pop();
    }

    int deck2 = DB::DeckRepository::addDeck("Czech A1");

    assert(DB::CardRepository::addCard(deck2, "taska", "bag"));
    assert(DB::CardRepository::addCard(deck2, "dzus", "juice"));
    assert(DB::CardRepository::addCard(deck2, "stul", "table"));
    assert(DB::CardRepository::addCard(deck2, "obchod", "shop"));
    assert(DB::CardRepository::addCard(deck2, "kniha", "book"));

    std::vector deck2Result = {
        std::make_pair<std::string, std::string>("taska", "bag"),
        std::make_pair<std::string, std::string>("dzus", "juice"),
        std::make_pair<std::string, std::string>("stul", "table"),
        std::make_pair<std::string, std::string>("obchod", "shop"),
        std::make_pair<std::string, std::string>("kniha", "book")
    };

    Core::Deck response2(deck2, "", "");
    DB::CardRepository::selectCardsByDeck(response2);

    const auto expectedSize = deck2Result.size();

    for (size_t i = 0; i < expectedSize; i++) {
        assert(deck2Result[i].first == response2.cardVector()[i].front() &&
               deck2Result[i].second == response2.cardVector()[i].back());
    }

    return 0;
}