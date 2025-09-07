import QtQuick
import QtQuick.Controls

import gui.element

Rectangle {
    id: root
    color: "#bebaba"

    ListView {
        interactive: false
        anchors.fill: parent

        spacing: 1

        ListModel {
            id: decks
            ListElement { deckId: 0; title: "English A2"; description: "Basic english conversation words" }
            ListElement { deckId: 1; title: "Spanish C2"; description: "Advanced spanish conversation words" }
            ListElement { deckId: 2; title: "Common Hungarian Phrases"; description: "Ozot nadyor konvesetes ogyo" }
            ListElement { deckId: 3; title: "Lesson 5"; description: "" }
        }

        model: decks

        delegate: DeckItem {
            deckId: model.deckId
            title: model.title
            description: model.description
        }
    }
}
