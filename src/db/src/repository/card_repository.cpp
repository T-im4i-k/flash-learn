#include "db/repository/card_repository.hpp"

#include "db/core/db_manager.hpp"
#include "db/query/card_query.hpp"

#include <QSqlError>
#include <QSqlQuery>

namespace DB {
    bool CardRepository::createTable() {
        QSqlQuery query(DBManager::database());
        query.prepare(CardQueries::createTable);
        return query.exec();
    }

    Core::Int CardRepository::addCard(const Core::Int deck_id,
                                      const QString &front,
                                      const QString &back) {
        QSqlQuery query(DBManager::database());
        query.prepare(CardQueries::insertCard);
        query.bindValue(":deck_id", deck_id);
        query.bindValue(":front", front);
        query.bindValue(":back", back);

        if (!query.exec()) {
            throw std::runtime_error(
                "CardRepository::addCard: SQL query failed.");
        }

        return query.lastInsertId().toInt();
    }

    void CardRepository::removeCard(const Core::Int card_id) {
        QSqlQuery query(DBManager::database());
        query.prepare(CardQueries::deleteCard);
        query.bindValue(":card_id", card_id);
        if (!query.exec()) {
            throw std::runtime_error(
                "CardRepository::removeCard: SQL query failed.");
        }
    }

    std::vector<Core::Card>
    CardRepository::getCardsInDeck(const Core::Int deck_id) {

        QSqlQuery query(DBManager::database());
        query.prepare(CardQueries::selectAll);
        query.bindValue(":deck_id", deck_id);

        if (!query.exec()) {
            throw std::runtime_error("CardRepository::getCardsInDeck: SQL "
                                     "query failed.");
        }

        std::vector<Core::Card> card_vector;
        while (query.next()) {
            card_vector.emplace_back(query.value(0).toInt(),
                                     query.value(1).toString().toStdString(),
                                     query.value(2).toString().toStdString());
        }

        return card_vector;
    }
} // namespace DB
