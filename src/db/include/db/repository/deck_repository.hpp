#pragma once

#include <QString>

#include "db/entity/deck_entity.hpp"

namespace DB {
    class DeckRepository {
    public:

        static bool createTable();

        static bool addDeck(const QString& title, const QString& description = "");

        static bool removeDeck(int deckId);

        static QList<DeckEntity> selectAllDecks();

    };
} // namespace DB