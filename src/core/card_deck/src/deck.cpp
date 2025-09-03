#include <algorithm>
#include <chrono>
#include <random>

#include "card_deck/deck.hpp"

namespace Core {
    Deck::Deck(const Int id, std::string title, std::string description,
               const std::initializer_list<Card> cards_list) :
        id_(id), title_(std::move(title)), description_(std::move(description)),
        card_vector_(cards_list), random_engine_(std::random_device{}()) {}

    Int Deck::getId() const { return id_; }

    const std::string &Deck::getTitle() const { return title_; }

    const std::string &Deck::getDescription() const { return description_; }

    void Deck::setTitle(std::string title) { title_ = std::move(title); }

    void Deck::setDescription(std::string description) {
        description_ = std::move(description);
    }

    std::vector<Card> &Deck::cardVector() { return card_vector_; }

    const std::vector<Card> &Deck::cardVector() const { return card_vector_; }

    void Deck::shuffle() { std::ranges::shuffle(card_vector_, random_engine_); }

} // namespace Core
