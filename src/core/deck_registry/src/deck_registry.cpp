#include "deck_registry/deck_registry.hpp"

namespace Core {
    DeckRegistry &DeckRegistry::getInstance() {
        static DeckRegistry registry;
        return registry;
    }
} // namespace Core
