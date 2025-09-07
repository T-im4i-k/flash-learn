#pragma once

namespace DeckQueries {
    inline constexpr auto createTable =
        "CREATE TABLE IF NOT EXISTS decks ("
        "deck_id INTEGER PRIMARY KEY AUTOINCREMENT,"
        "title TEXT NOT NULL,"
        "description TEXT NOT NULL)";

    inline constexpr auto insertDeck = "INSERT INTO decks (title, description) "
                                       "VALUES (:title, :description)";

    inline constexpr auto deleteDeck =
        "DELETE FROM decks WHERE deck_id = :deck_id";

    inline constexpr auto selectAll = "SELECT * FROM decks";
} // namespace DeckQueries
