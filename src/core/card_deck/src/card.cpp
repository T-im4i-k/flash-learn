#include "card_deck/card.hpp"

namespace Core {
    Card::Card(const Int id, std::string front, std::string back) :
        id_(id), front_(std::move(front)), back_(std::move(back)) {}

    Int Card::id() const { return id_; }

    const std::string &Card::front() const { return front_; }

    std::string &Card::front() { return front_; }

    const std::string &Card::back() const { return back_; }

    std::string &Card::back() { return back_; }

} // namespace Core
