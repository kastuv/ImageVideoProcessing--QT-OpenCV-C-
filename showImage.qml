import QtQuick
import QtQuick.Controls
import QtQuick.Layouts

Page {
    //anchors.fill: parent

    Rectangle
    {
        id: bar
        width: parent.width
        height: parent.height * 0.1
        color: "green"

        Label
        {
            text: "<html><h2>Show Image</h2></html>"
            color: "white"
            anchors.centerIn: parent
        }

        Text {
            id: name
            text: qsTr("<html><i>- By Kaustuv Pokharel</i></html>")
            anchors.right: bar.right
            anchors.rightMargin: 15
            anchors.verticalCenter: bar.verticalCenter
            color: "white"
        }

        ColumnLayout
        {
            id: imageContainer
            width: 680
            height: 480

            anchors.top: bar.bottom
            anchors.topMargin: 20
            anchors.horizontalCenter: parent.horizontalCenter

            Image {
                id: picture
                source: "qrc:/logo"
                Layout.preferredWidth: imageContainer.width
                Layout.preferredHeight: imageContainer.height
                fillMode: Image.PreserveAspectFit
            }
        }

        RowLayout
        {
            anchors.top: imageContainer.bottom
            anchors.topMargin: 10
            anchors.horizontalCenter: parent.horizontalCenter
            width : parent.width * 0.6
            spacing: width*0.2

            Button
            {
                text: "Open Image"
                Layout.preferredWidth: parent.width * 0.4
            }
            Button
            {
                text: "Go Back"
                Layout.preferredWidth: parent.width * 0.4
                onClicked: loader.pop()
            }
        }

    }
}
