#pragma once

#include <string>

#include "alias/alias.hpp"

namespace Cards {
    class Card {
    public:
        Card(Aliases::Integer id, std::string front, std::string back);

        [[nodiscard]] Aliases::Integer getId() const;

        [[nodiscard]] const std::string &getFront() const;

        [[nodiscard]] const std::string &getBack() const;

        void setFront(std::string front);

        void setBack(std::string back);

    private:
        Aliases::Integer id_;
        std::string front_;
        std::string back_;
    };
} // namespace Cards
