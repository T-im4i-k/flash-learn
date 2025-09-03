#pragma once

#include <random>
#include <string>
#include <vector>

#include "alias/alias.hpp"
#include "card_deck/card.hpp"

namespace Core {
    class Deck {
    public:
        using DeckIt = std::vector<Card>::iterator;
        using ConstDeckIt = std::vector<Card>::const_iterator;

        explicit Deck(Int id, std::string title, std::string description,
                      std::initializer_list<Card> cards_list = {});

        [[nodiscard]] Int getId() const;

        [[nodiscard]] const std::string &getTitle() const;

        [[nodiscard]] const std::string &getDescription() const;

        void setTitle(std::string title);

        void setDescription(std::string description);

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
        Int id_;
        std::string title_;
        std::string description_;
        std::vector<Card> cards_vector_;
        std::mt19937_64 random_engine_;
    };
} // namespace Core
