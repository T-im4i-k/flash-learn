import QtQuick
import QtQuick.Controls

Rectangle {
    property color baseColor: "#847E89"
    signal clicked()

    id: root
    color:  if(area.pressed)
        return Qt.darker(baseColor, 1.1)
    else if(area.containsMouse)
        return Qt.lighter(baseColor, 1.05)
    else
        return baseColor

    radius: 30

    Text {
        text: "+"
        font {
            pixelSize: 35
            bold: true
        }

        color: "#C2D3CD"

        anchors.centerIn: parent
    }

    MouseArea {
        id: area

        anchors.fill: parent
        hoverEnabled: true

        onClicked: { root.clicked() }
    }
}
