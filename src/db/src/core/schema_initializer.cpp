#include "db/core/schema_initializer.hpp"

#include "db/repository/card_repository.hpp"
#include "db/repository/deck_repository.hpp"

namespace DB {
    void SchemaInitializer::initialize() {
        DeckRepository::createTable();
        CardRepository::createTable();
    }
} // namespace DB