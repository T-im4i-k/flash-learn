#pragma once

#include <string>

#include "alias/alias.hpp"

namespace Core {
    class Card {
    public:
        Card(Int id, std::string front, std::string back);

        [[nodiscard]] Int getId() const;

        [[nodiscard]] const std::string &getFront() const;

        [[nodiscard]] const std::string &getBack() const;

        void setFront(std::string front);

        void setBack(std::string back);

    private:
        Int id_;
        std::string front_;
        std::string back_;
    };
} // namespace Core
