import QtQuick
import QtQuick.Controls

import gui.element

Rectangle {
    id: root

    color: "#bebaba"

    ListView {
        anchors.fill: parent
        interactive: false
        model: decks
        spacing: 1

        delegate: DeckItem {
            deckId: model.deckId
            description: model.description
            title: model.title
        }

        ListModel {
            id: decks

            ListElement {
                deckId: 0
                description: "Basic english conversation words"
                title: "English A2"
            }
            ListElement {
                deckId: 1
                description: "Advanced spanish conversation words"
                title: "Spanish C2"
            }
            ListElement {
                deckId: 2
                description: "Ozot nadyor konvesetes ogyo"
                title: "Common Hungarian Phrases"
            }
            ListElement {
                deckId: 3
                description: ""
                title: "Lesson 5"
            }
        }
    }
}
