import QtQuick

Window {
    height: 350
    title: qsTr("Main Gui Window")
    visible: true
    width: 350

    Text {
        anchors.centerIn: parent
        font.pixelSize: 24
        text: "Hello There!"
    }
}