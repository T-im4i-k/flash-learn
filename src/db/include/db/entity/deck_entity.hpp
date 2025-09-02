#pragma once
#include <QString>

namespace DB {
    class DeckEntity {
    public:
        DeckEntity() = default;
        DeckEntity(int id, QString front, QString back);

        int id_;
        QString front_;
        QString back_;
    };
} // namespace DB