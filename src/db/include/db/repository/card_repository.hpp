#pragma once

#include <QString>

#include "card_deck/deck.hpp"

namespace DB {
    class CardRepository {
    public:

        static bool createTable();

        static bool addCard(int deckId, const QString & front, const QString & back);

        static bool removeCard(int deckId, int cardId);

        static Core::Deck selectCardsByDeckId(int deckId);

    };
} // namespace DB