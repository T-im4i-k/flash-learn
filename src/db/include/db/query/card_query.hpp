#pragma once

namespace CardQueries {
    inline constexpr auto createTable =
        "CREATE TABLE IF NOT EXISTS cards ("
        "card_id INTEGER PRIMARY KEY AUTOINCREMENT,"
        "deck_id INTEGER,"
        "front TEXT NOT NULL,"
        "back TEXT NOT NULL,"
        "FOREIGN KEY(deck_id) REFERENCES decks(id))";

    inline constexpr auto insertCard =
        "INSERT INTO cards(deck_id, front, back)"
        "VALUES (:deck_id, :front, :back)";

    inline constexpr auto deleteCard =
        "DELETE FROM cards WHERE deck_id = :deck_id AND card_id = :card_id";

    inline constexpr auto selectAll =
        "SELECT card_id, front, back FROM cards WHERE deck_id = :deck_id";
} // namespace CardQueries
