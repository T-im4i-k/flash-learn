#pragma once

#include "alias/alias.hpp"
#include "card_deck/card.hpp"

#include <random>
#include <string>
#include <vector>

namespace Core {
    class Deck {
    public:
        Deck(Int id, std::string title, std::string description,
             std::initializer_list<Card> card_list = {});

        [[nodiscard]] Int id() const;

        [[nodiscard]] const std::string &title() const;

        [[nodiscard]] const std::string &description() const;

        [[nodiscard]] std::string &title();

        [[nodiscard]] std::string &description();

        [[nodiscard]] std::vector<Card> &cardVector();

        [[nodiscard]] const std::vector<Card> &cardVector() const;

        void shuffle();

    private:
        Int id_;
        std::string title_;
        std::string description_;
        std::vector<Card> card_vector_;
        std::mt19937_64 random_engine_;
    };
} // namespace Core
