import QtQuick
import QtQuick.Controls

Rectangle {
    id: root
    width: parent.width
    height: 60

    color: "#acabab"

    TextField {
        anchors.fill: parent
        anchors.margins: 10
        placeholderText: "Search..."

        leftPadding: 10
        rightPadding: 10

        font.pixelSize: 17
    }
}
