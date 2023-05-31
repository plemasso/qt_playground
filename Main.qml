import QtQuick
import QtQuick.Window
import MyNavigatorPackage 1.0
import SimpleMenu


Window {
    width: 640
    height: 480
    visible: true
    title: qsTr("My super thermostat")

    /*SimpleMenu{
        xPos: 200
        yPos: 250
    }*/

    DummyWidget{

    }

    Item {
        id:root

        x:10
        y:200

        property int currentScreen: MyUniqueNavigatorCaptainAPI.currentScreen

        Rectangle{
            width: 150
            height: 40
            color: "red"
            radius: 12

            Text{
                width: parent.width
                height: parent.height
                anchors.fill: parent
                anchors.margins: 2
                horizontalAlignment: Text.AlignHCenter
                verticalAlignment: Text.AlignVCenter
                text: "Current screen: " + root.currentScreen
            }

            MouseArea{
                anchors.fill: parent
                onClicked:{
                    MyUniqueNavigatorCaptainAPI.goToScreen(root.currentScreen + 1)
                }
            }
        }
    }

    NavButton{
        xPos: 10
        yPos: 250
        screenNavTarget: 1
    }

    NavButton{
        xPos: 60
        yPos: 250
        screenNavTarget: 2
    }

    NavButton{
        xPos: 110
        yPos: 250
        screenNavTarget: 3
    }
}
