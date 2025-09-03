#include "db/core/db_manager.hpp"

namespace DB {

    bool DBManager::open(const QString & path) {
        if (db_.isOpen())
            return true;

        db_ = QSqlDatabase::addDatabase("QSQLITE");
        db_.setDatabaseName(path);

        if (!db_.open()) {
            qWarning() << "Failed to connect.";
            return false;
        }

        return true;
    }

    QSqlDatabase& DBManager::database() {
        return db_;
    }


    bool DBManager::close() {
        if (db_.isOpen()) {
            db_.close();
            return true;
        }

        return false;
    }
} // namespace DB