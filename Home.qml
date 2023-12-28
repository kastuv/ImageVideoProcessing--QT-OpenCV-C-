import QtQuick
import QtQuick.Controls

Page {
    //anchors.fill: parent
    //We would never use fill parent for the pages, as it is a page and fill automatically.

    Rectangle
    {
        id: bar
        width: parent.width
        height: parent.height * 0.1
        color: "green"

        Label
        {
            text: "<html><h2><i>OpenCV</i> with QT</h2></html>"
            color: "white"
            anchors.centerIn: parent
        }

        Text
        {
            id: name
            text: qsTr("<html><i>- By Kaustuv Pokharel</i></html>")
            anchors.right: bar.right
            anchors.rightMargin: 15
            anchors.verticalCenter: bar.verticalCenter
            color: "white"
        }

    }

    Button
    {
        id: button1
        text: "Show Image"
        anchors.top: bar.bottom
        anchors.topMargin: 20
        anchors.horizontalCenter: parent.horizontalCenter
        onClicked: loader.push("qrc:/ImageVideoProcess/showImage.qml")
    }
}
