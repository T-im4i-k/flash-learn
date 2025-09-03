#include <QSqlQuery>
#include <QSqlError>

#include "db/repository/card_repository.hpp"

#include "db/core/db_manager.hpp"
#include "db/query/card_query.hpp"

namespace DB {

    bool CardRepository::createTable() {
        QSqlQuery query(DBManager::getInstance().database());
        query.prepare(CardQueries::createTable);
        return query.exec();
    }

    bool CardRepository::addCard(const Core::Int deckId, const QString &  front, const QString &  back) {
        QSqlQuery query(DBManager::getInstance().database());
        query.prepare(CardQueries::insertCard);
        query.bindValue(":deck_id", deckId);
        query.bindValue(":front", front);
        query.bindValue(":back", back);

        return query.exec();
    }

    bool CardRepository::removeCard(const Core::Int deckId, const Core::Int cardId) {
        QSqlQuery query(DBManager::getInstance().database());
        query.prepare(CardQueries::deleteCard);
        query.bindValue(":card_id", cardId);
        query.bindValue(":deck_id", deckId);

        return query.exec();
    }

    bool CardRepository::selectCardsByDeck(Core::Deck & deck) {
        QSqlQuery query(DBManager::getInstance().database());
        query.prepare(CardQueries::selectAll);
        query.bindValue(":deck_id", deck.getId());

        if (!query.exec()) {
            qWarning() << "Failed to select cards:" << query.lastError().text();
            return false;
        }

        while (query.next()) {
            Core::Card card(query.value(0).toInt(),
                         query.value(1).toString().toStdString(),
                         query.value(2).toString().toStdString());

            deck.pushBack(card);
        }

        return true;
    }
} // namespace DB