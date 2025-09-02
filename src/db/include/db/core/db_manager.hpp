#pragma once

#include <QSqlDatabase>

namespace DB {
    class DBManager {
    public:
        static DBManager & getInstance();

        bool open(const QString & path);

        QSqlDatabase& database();

        ~DBManager();
    private:
        DBManager() = default;
        QSqlDatabase db_;
    };
} // namespace DB
