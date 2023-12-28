import QtQuick
import QtQuick.Window
import QtQuick.Controls

Window {
    width: 1024
    height: 720
    visible: true
    color: "#222222"
    title: qsTr("ImageViewer")

    StackView
    {
        id: loader
        anchors.fill:parent
        initialItem: "qrc:/ImageVideoProcess/Home.qml"
    }

}
