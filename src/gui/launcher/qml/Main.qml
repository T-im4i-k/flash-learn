import QtQuick
import gui.widget
import gui.view

Window {
    height: 580
    title: qsTr("Flash-learn")
    visible: true
    width: 740

    SearchPanel {
        id: searchpanel

        anchors.left: parent.left
        anchors.right: parent.right
        anchors.top: parent.top
    }
    DeckView {
        anchors.bottom: bottombar.top
        anchors.left: parent.left
        anchors.right: parent.right
        anchors.top: searchpanel.bottom
    }
    Rectangle {
        id: bottombar

        anchors.bottom: parent.bottom
        anchors.left: parent.left
        anchors.right: parent.right
        color: "#4f5053"
        height: 70

        AddButton {
            id: addbutton

            anchors.bottom: parent.bottom
            anchors.margins: 10
            anchors.right: parent.right
            height: 50
            width: 50

            onClicked: add_dialog.visible = true
        }
    }
    AddDeckDialog {
        id: add_dialog

    }
}
