#pragma once

#include <QString>

#include "card_deck/deck.hpp"

namespace DB {
    class DeckRepository {
    public:
        static bool createTable();

        static Core::Int addDeck(const QString &title,
                                 const QString &description = "");

        static bool removeDeck(Core::Int deckId);

        static void fillDeckRegistry();
    };
} // namespace DB
