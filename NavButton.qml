import QtQuick
import MyNavigatorPackage 1.0

Item {
    id:root

    property real xPos: 0
    property real yPos: 0
    property real screenNavTarget: 0

    Rectangle{
        x: root.xPos
        y: root.yPos
        width: 40
        height: 40
        color: "green"
        radius: 12

        Text{
            width: parent.width
            height: parent.height
            anchors.fill: parent
            anchors.margins: 2
            horizontalAlignment: Text.AlignHCenter
            verticalAlignment: Text.AlignVCenter
            text: root.screenNavTarget
        }

        MouseArea{
            anchors.fill: parent
            onClicked:{
                MyUniqueNavigatorCaptainAPI.goToScreen(root.screenNavTarget)
            }
        }
    }
}
