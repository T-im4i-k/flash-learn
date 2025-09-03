#include <QSqlQuery>

#include "db/repository/deck_repository.hpp"

#include "card_deck/deck.hpp"
#include "db/core/db_manager.hpp"
#include "db/query/deck_query.hpp"

namespace DB {
    bool DeckRepository::createTable() {
        QSqlQuery query(DBManager::database());
        query.prepare(DeckQueries::createTable);

        return query.exec();
    }

    bool DeckRepository::addDeck(const QString& title, const QString& description) {
        QSqlQuery query(DBManager::database());
        query.prepare(DeckQueries::insertDeck);
        query.bindValue(":title", title);
        query.bindValue(":description", description);

        return query.exec();
    }

    bool DeckRepository::removeDeck(const Core::Int deckId) {
        QSqlQuery query(DBManager::database());
        query.prepare(DeckQueries::deleteDeck);
        query.bindValue(":deck_id", deckId);

        return query.exec();
    }

    QList<Core::Deck> DeckRepository::selectAllDecks() {
        QList<Core::Deck> decks;
        QSqlQuery query(DBManager::database());
        query.prepare(DeckQueries::selectAll);

        if (query.exec()) {
            Core::Deck deck(query.value(0).toInt(),
                            query.value(1).toString().toStdString(),
                            query.value(2).toString().toStdString());

            decks.append(deck);
        }

        return decks;
    }

} // namespace DB