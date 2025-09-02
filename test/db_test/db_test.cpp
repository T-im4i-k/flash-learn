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

    DB::DBManager::getInstance().open(":memory:");
    DB::SchemaInitializer::initialize();

    assert(DB::DeckRepository::addDeck("Spanish A2"));

    assert(DB::CardRepository::addCard(0, "aburrido", "boring"));
    assert(DB::CardRepository::addCard(0, "salsa", "sauce"));
    assert(DB::CardRepository::addCard(0, "sombrero", "hat"));

    std::queue<std::string> result;
    result.emplace("aburrido");
    result.emplace("salsa");
    result.emplace("sombrero");

    Core::Deck response = DB::CardRepository::selectCardsByDeckId(0);

    assert(!response.empty());

    for (const auto& card : response) {
        assert(card.getFront() == result.front());
        result.pop();
    }

    return 0;
}