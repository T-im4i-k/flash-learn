#pragma once

#include <random>
#include <vector>

#include "alias/alias.hpp"
#include "card/card.hpp"

namespace Cards {
    class Deck {
    public:
        using DeckIt = std::vector<Card>::iterator;
        using ConstDeckIt = std::vector<Card>::const_iterator;

        explicit Deck(Aliases::Integer id,
                      std::initializer_list<Card> cards_list = {});

        [[nodiscard]] Aliases::Integer getId() const;

        DeckIt erase(DeckIt it);

        void pushBack(Card card);

        [[nodiscard]] DeckIt begin();

        [[nodiscard]] DeckIt end();

        [[nodiscard]] ConstDeckIt begin() const;

        [[nodiscard]] ConstDeckIt end() const;

        [[nodiscard]] size_t size() const;

        [[nodiscard]] bool empty() const;

        void shuffle();

    private:
        Aliases::Integer id_;
        std::vector<Card> cards_vector_;
        std::mt19937_64 random_engine_;
    };
} // namespace Cards
