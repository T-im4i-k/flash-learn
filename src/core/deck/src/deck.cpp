#include <algorithm>
#include <chrono>
#include <random>

#include "deck/deck.hpp"

namespace Core {
    Deck::Deck(const Integer id, const std::initializer_list<Card> cards_list) :
        id_(id), cards_vector_(cards_list),
        random_engine_(std::random_device{}()) {}

    Integer Deck::getId() const { return id_; }

    Deck::DeckIt Deck::erase(const DeckIt it) {
        return cards_vector_.erase(it);
    }

    void Deck::pushBack(Card card) { cards_vector_.push_back(std::move(card)); }

    Deck::DeckIt Deck::begin() { return cards_vector_.begin(); }

    Deck::DeckIt Deck::end() { return cards_vector_.end(); }

    Deck::ConstDeckIt Deck::begin() const { return cards_vector_.cbegin(); }

    Deck::ConstDeckIt Deck::end() const { return cards_vector_.cend(); }

    size_t Deck::size() const { return cards_vector_.size(); }

    bool Deck::empty() const { return cards_vector_.empty(); }

    void Deck::shuffle() {
        std::ranges::shuffle(cards_vector_, random_engine_);
    }

} // namespace Core
