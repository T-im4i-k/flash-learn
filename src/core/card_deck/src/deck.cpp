#include "card_deck/deck.hpp"

#include <algorithm>
#include <chrono>
#include <random>

namespace Core {
    Deck::Deck(const Int id, std::string title, std::string description,
               const std::initializer_list<Card> card_list)
        : id_(id), title_(std::move(title)),
          description_(std::move(description)), card_vector_(card_list),
          random_engine_(std::random_device{}()) {}

    Int Deck::id() const { return id_; }

    const std::string &Deck::title() const { return title_; }

    const std::string &Deck::description() const { return description_; }

    std::string &Deck::title() { return title_; }

    std::string &Deck::description() { return description_; }

    std::vector<Card> &Deck::cardVector() { return card_vector_; }

    const std::vector<Card> &Deck::cardVector() const { return card_vector_; }

    void Deck::shuffle() { std::ranges::shuffle(card_vector_, random_engine_); }
} // namespace Core
