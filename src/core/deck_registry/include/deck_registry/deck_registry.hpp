#pragma once

#include <vector>

#include "card_deck/deck.hpp"

namespace Core {
    class DeckRegistry {
    public:
        static DeckRegistry &getInstance();

        std::vector<Deck> deck_vector_;

    private:
        DeckRegistry() = default;
    };
} // namespace Core
