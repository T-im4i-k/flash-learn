import QtQuick
import QtQuick.Controls

ToolButton {
    font.pixelSize: 20

    contentItem: Text {
        anchors.centerIn: parent
        color: "black"
        font.pixelSize: 24
        text: "\u22EE"
    }

    onClicked: menu.open()

    Menu {
        id: menu

        MenuItem {
            text: "Add"
        }
        MenuItem {
            text: "Delete"
        }
        MenuItem {
            text: "Edit"
        }
    }
}
