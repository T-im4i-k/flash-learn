#pragma once

#include <QString>

#include "card_deck/deck.hpp"

namespace DB {
    class CardRepository {
    public:
        static bool createTable();

        static Core::Int addCard(Core::Int deckId, const QString &front,
                                 const QString &back);

        static bool removeCard(Core::Int deckId, Core::Int cardId);

        static bool selectCardsByDeck(Core::Deck &deck);
    };
} // namespace DB
