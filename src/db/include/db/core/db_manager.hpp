#pragma once

#include <QSqlDatabase>

namespace DB {
    class DBManager {
    public:
        static bool open(const QString &path);

        static bool close();

        static QSqlDatabase &database();

    private:
        static inline QSqlDatabase db_;
    };
} // namespace DB
