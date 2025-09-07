import QtQuick
import QtQuick.Controls

Rectangle {
    id: root

    color: "#acabab"
    height: 60
    width: parent.width

    TextField {
        anchors.fill: parent
        anchors.margins: 10
        font.pixelSize: 17
        leftPadding: 10
        placeholderText: "Search..."
        rightPadding: 10
    }
}
