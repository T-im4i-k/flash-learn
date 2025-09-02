#include "card_deck/card.hpp"

namespace Core {
    Card::Card(const Int id, std::string front, std::string back) :
        id_(id), front_(std::move(front)), back_(std::move(back)) {}

    Int Card::getId() const { return id_; }

    const std::string &Card::getFront() const { return front_; }

    const std::string &Card::getBack() const { return back_; }

    void Card::setBack(std::string back) { back_ = std::move(back); }

    void Card::setFront(std::string front) { front_ = std::move(front); }


} // namespace Core
