#include <QSqlError>
#include <QSqlQuery>

#include "db/repository/deck_repository.hpp"

#include "card_deck/deck.hpp"
#include "db/core/db_manager.hpp"
#include "db/query/deck_query.hpp"
#include "deck_registry/deck_registry.hpp"

namespace DB {
    bool DeckRepository::createTable() {
        QSqlQuery query(DBManager::database());
        query.prepare(DeckQueries::createTable);
        return query.exec();
    }

    Core::Int DeckRepository::addDeck(const QString &title,
                                      const QString &description) {
        QSqlQuery query(DBManager::database());
        query.prepare(DeckQueries::insertDeck);
        query.bindValue(":title", title);
        query.bindValue(":description", description);

        if (!query.exec()) {
            throw std::runtime_error(
                    "DeckRepository::addDeck: SQL query failed");
        }

        return query.lastInsertId().toInt();
    }

    bool DeckRepository::removeDeck(const Core::Int deckId) {
        QSqlQuery query(DBManager::database());
        query.prepare(DeckQueries::deleteDeck);
        query.bindValue(":deck_id", deckId);

        return query.exec();
    }

    void DeckRepository::fillDeckRegistry() {
        QSqlQuery query(DBManager::database());
        query.prepare(DeckQueries::selectAll);

        if (!query.exec()) {
            throw std::runtime_error("DeckRepository::fillDeckRegistry: SQL "
                                     "query failed.");
        }

        while (query.next()) {
            Core::DeckRegistry::getInstance().deck_vector_.emplace_back(
                    query.value(0).toInt(),
                    query.value(1).toString().toStdString(),
                    query.value(2).toString().toStdString());
        }
    }

} // namespace DB
