import QtQuick
import QtQuick.Controls
import QtQuick.Layouts

Dialog {
    id: deckDialog

    anchors.centerIn: parent
    height: 300
    modal: true
    standardButtons: Dialog.Ok | Dialog.Cancel
    title: "New Deck"
    width: 300

    onAccepted: {
        console.log("Deck name:", nameField.text);
        console.log("Description:", descriptionField.text);
    }

    GridLayout {
        anchors.fill: parent
        columns: 1
        rows: 2

        TextField {
            id: nameField

            Layout.fillWidth: true
            placeholderText: "Deck name"
        }
        TextArea {
            id: descriptionField

            Layout.fillHeight: true
            Layout.fillWidth: true
            placeholderText: "Description"
            wrapMode: TextEdit.Wrap

            background: Rectangle {
                border.color: "#888"
                border.width: 1
                color: "transparent"
                radius: 4
            }
        }
    }
}
