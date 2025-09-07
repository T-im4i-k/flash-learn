#pragma once

#include "card_deck/deck.hpp"

#include <QString>

namespace DB {
    class CardRepository {
    public:
        static bool createTable();

        static Core::Int addCard(Core::Int deck_id, const QString &front,
                                 const QString &back);

        static void removeCard(Core::Int card_id);

        static std::vector<Core::Card> getCardsInDeck(Core::Int deck_id);
    };
} // namespace DB
