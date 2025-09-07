#pragma once

#include "card_deck/deck.hpp"

#include <vector>

namespace Core {
    class DeckRegistry {
    public:
        static DeckRegistry &getInstance();

        std::vector<Deck> deck_vector_;

    private:
        DeckRegistry() = default;
    };
} // namespace Core
