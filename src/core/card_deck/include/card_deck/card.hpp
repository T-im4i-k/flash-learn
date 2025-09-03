#pragma once

#include <string>

#include "alias/alias.hpp"

namespace Core {
    class Card {
    public:
        Card(Int id, std::string front, std::string back);

        [[nodiscard]] Int id() const;

        [[nodiscard]] const std::string &front() const;

        [[nodiscard]] std::string &front();

        [[nodiscard]] const std::string &back() const;

        [[nodiscard]] std::string &back();

    private:
        Int id_;
        std::string front_;
        std::string back_;
    };
} // namespace Core
