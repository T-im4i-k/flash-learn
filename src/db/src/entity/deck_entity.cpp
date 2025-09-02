#include "db/entity/deck_entity.hpp"

namespace DB {
    DeckEntity::DeckEntity(int id, QString front, QString back)
        : id_(id), front_(std::move(front)), back_(std::move(back)) {}
} // namespace DB