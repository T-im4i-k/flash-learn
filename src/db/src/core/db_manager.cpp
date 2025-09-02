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

    DBManager & DBManager::getInstance() {
        static DBManager instance;
        return instance;
    }

    QSqlDatabase& DBManager::database() {
        return db_;
    }


    DBManager::~DBManager() {
        if (db_.isOpen()) {
            db_.close();
        }
    }
} // namespace DB