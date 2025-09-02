#include <QSqlQuery>

#include "db/repository/deck_repository.hpp"

#include "db/core/db_manager.hpp"
#include "db/query/deck_query.hpp"

namespace DB {
    bool DeckRepository::createTable() {
        QSqlQuery query(DBManager::getInstance().database());
        query.prepare(DeckQueries::createTable);

        return query.exec();
    }

    bool DeckRepository::addDeck(const QString& title, const QString& description) {
        QSqlQuery query(DBManager::getInstance().database());
        query.prepare(DeckQueries::insertDeck);
        query.bindValue(":title", title);
        query.bindValue(":description", description);

        return query.exec();
    }

    bool DeckRepository::removeDeck(const int deckId) {
        QSqlQuery query(DBManager::getInstance().database());
        query.prepare(DeckQueries::deleteDeck);
        query.bindValue(":deck_id", deckId);

        return query.exec();
    }

    QList<DeckEntity> DeckRepository::selectAllDecks() {
        QList<DeckEntity> decks;
        QSqlQuery query(DBManager::getInstance().database());
        query.prepare(DeckQueries::selectAll);

        if (query.exec()) {
            decks.append({query.value(0).toInt(),
                            query.value(1).toString(),
                            query.value(2).toString()});
        }

        return decks;
    }

} // namespace DB