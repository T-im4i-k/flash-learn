import QtQuick
import QtQuick.Controls

ToolButton {
    font.pixelSize: 20

    contentItem: Text {
        text: "\u22EE"
        anchors.centerIn: parent
        font.pixelSize: 24
        color: "black"
    }

    onClicked: menu.open()

    Menu {
        id: menu
        MenuItem { text: "Add" }
        MenuItem { text: "Delete" }
        MenuItem { text: "Edit" }
    }
}
