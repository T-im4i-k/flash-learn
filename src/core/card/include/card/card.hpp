#pragma once

#include <string>

#include "alias/alias.hpp"

namespace Core {
    class Card {
    public:
        Card(Integer id, std::string front, std::string back);

        [[nodiscard]] Integer getId() const;

        [[nodiscard]] const std::string &getFront() const;

        [[nodiscard]] const std::string &getBack() const;

        void setFront(std::string front);

        void setBack(std::string back);

    private:
        Integer id_;
        std::string front_;
        std::string back_;
    };
} // namespace Core
