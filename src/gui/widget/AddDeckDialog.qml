import QtQuick
import QtQuick.Controls
import QtQuick.Layouts

Dialog {
    id: deckDialog
    title: "New Deck"
    modal: true
    width: 300
    height: 300
    standardButtons: Dialog.Ok | Dialog.Cancel
    anchors.centerIn: parent

    GridLayout {
        rows: 2
        columns: 1
        anchors.fill: parent

        TextField {
            id: nameField
            Layout.fillWidth: true
            placeholderText: "Deck name"
        }

        TextArea {
            id: descriptionField
            placeholderText: "Description"
            Layout.fillWidth: true
            Layout.fillHeight: true

            wrapMode: TextEdit.Wrap



            background: Rectangle {
                color: "transparent"
                border.color: "#888"
                border.width: 1
                radius: 4
            }
        }
    }

    onAccepted: {
        console.log("Deck name:", nameField.text)
        console.log("Description:", descriptionField.text)
    }
}
