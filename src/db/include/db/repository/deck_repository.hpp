#pragma once

#include <QString>

#include "card_deck/deck.hpp"


namespace DB {
    class DeckRepository {
    public:

        static bool createTable();

        static bool addDeck(const QString& title, const QString& description = "");

        static bool removeDeck(Core::Int deckId);

        static QList<Core::Deck> selectAllDecks();

    };
} // namespace DB