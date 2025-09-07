import QtQuick
import gui.widget
import gui.view

Window {
    width: 740
    height: 580
    visible: true
    title: qsTr("Flash-learn")

    SearchPanel {
        id: searchpanel

        anchors.top: parent.top
        anchors.left: parent.left
        anchors.right: parent.right

    }

    DeckView {
        anchors.top: searchpanel.bottom
        anchors.left: parent.left
        anchors.right: parent.right
        anchors.bottom: bottombar.top
    }

    Rectangle {
        id: bottombar
        color: "#4f5053"

        height: 70

        anchors.right: parent.right
        anchors.left: parent.left
        anchors.bottom: parent.bottom

        AddButton {
            id: addbutton
            width: 50
            height: 50
            anchors.margins: 10

            anchors.right: parent.right
            anchors.bottom: parent.bottom

            onClicked: add_dialog.visible = true
        }
    }


    AddDeckDialog { id: add_dialog }
}
