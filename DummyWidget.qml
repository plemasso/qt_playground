import QtQuick
import Playground
import MyDataModelPackage 1.0

Item {
    id: root

    // Dummy example, shall not be defined here
    x: 10
    y: 20

    // --- Other option ---
    // Instanciation of the data model c++ class
    // C++ class data model is accessible via "instantiable QML Type"
    /*DataModel{
        id: myDataModel
        onTemperatureChanged: ()=> console.log("Temperature changed, do something")

    }*/

    // --- Option 2: via registered type ---
    // Instanciate the type in qml
    DataModel{
        id: myDataModel
    }

    Rectangle{
        id: backgroundRect
        color: "lightGrey"
        x: root.x
        y: root.y
        height: 30
        width: 200
        radius: 5
        Text{
            width: parent.width
            height: parent.height
            anchors.fill: parent
            anchors.margins: 2
            horizontalAlignment: Text.AlignHCenter
            verticalAlignment: Text.AlignVCenter

            // Read access of the data model class
            //text: "Temp: " + myDataModel.temperature + "°C"

            // --- Option 1: via context property ---
            // Access C++ data (context property)
            //text: "Temp: " + myDataModelGlobal.temperature + "°C"

            // --- Option 2: via registered type ---
            text: "Temp: " + myDataModel.temperature + "°C"
        }
    }

    Rectangle{
        id: plusRect
        color: Qt.rgba(1,1,0,0.3)
        x: root.x + backgroundRect.width - backgroundRect.height
        y: root.y
        height: backgroundRect.height
        width: backgroundRect.height
        radius: 5
        Text{
            width: parent.width
            height: parent.height
            anchors.fill: parent
            anchors.margins: 2
            horizontalAlignment: Text.AlignHCenter
            verticalAlignment: Text.AlignVCenter
            text: "+"
        }
        MouseArea{
            anchors.fill: parent
            onClicked:{
                // --- Option 2: via registered type ---
                myDataModel.increaseTemperature(1)
            }
        }
    }

    Rectangle{
        id: minusRect
        color: Qt.rgba(1,1,0,0.3)
        x: root.x
        y: root.y
        height: backgroundRect.height
        width: backgroundRect.height
        radius: 5
        Text{
            width: parent.width
            height: parent.height
            anchors.fill: parent
            anchors.margins: 2
            horizontalAlignment: Text.AlignHCenter
            verticalAlignment: Text.AlignVCenter
            text: "-"
        }
        MouseArea{
            anchors.fill: parent
            onClicked:{
                // --- Option 2: via registered type ---
                //myDataModel.decreaseTemperature(1)
                myDataModel.temperature = 20
            }
        }
    }

    Rectangle{
        id: anotherButton
        color: Qt.rgba(0.1,0.5,0.1,0.3)
        x: root.x
        y: root.y + backgroundRect.height + 10
        height: backgroundRect.height
        width: backgroundRect.width * 0.5
        radius: 5
        Text{
            width: parent.width
            height: parent.height
            anchors.fill: parent
            anchors.margins: 2
            horizontalAlignment: Text.AlignHCenter
            verticalAlignment: Text.AlignVCenter
            text: "Reset temp"
        }
        MouseArea{
            anchors.fill: parent
            onClicked:{
                // --- Option 1: via context property ---
                //myDataModelGlobal.resetTemp()

                // --- Option 2: via registered type ---
                myDataModel.resetTemp()
            }
        }
    }
// -------------------------------------
    Rectangle{
        id: backgroundRect2
        color: "lightGrey"
        x: root.x + 300
        y: root.y
        height: 30
        width: 200
        radius: 5
        Text{
            width: parent.width
            height: parent.height
            anchors.fill: parent
            anchors.margins: 2
            horizontalAlignment: Text.AlignHCenter
            verticalAlignment: Text.AlignVCenter

            // Read access of the data model class
            //text: "Temp: " + myDataModel.temperature + "°C"

            // --- Option 1: via context property ---
            // Access C++ data (context property)
            //text: "Temp: " + myDataModelGlobal.temperature + "°C"

            // --- Option 2: via registered type ---
            text: "Temp: " + myDataModel.pressure + "bar"
        }
    }

    Rectangle{
        id: plusRect2
        color: Qt.rgba(1,1,0,0.3)
        x: root.x + 300 + backgroundRect.width - backgroundRect.height
        y: root.y
        height: backgroundRect.height
        width: backgroundRect.height
        radius: 5
        Text{
            width: parent.width
            height: parent.height
            anchors.fill: parent
            anchors.margins: 2
            horizontalAlignment: Text.AlignHCenter
            verticalAlignment: Text.AlignVCenter
            text: "+"
        }
        MouseArea{
            anchors.fill: parent
            onClicked:{
                // --- Option 2: via registered type ---
                myDataModel.pressure++
            }
        }
    }

    Rectangle{
        id: minusRect2
        color: Qt.rgba(1,1,0,0.3)
        x: root.x + 300
        y: root.y
        height: backgroundRect.height
        width: backgroundRect.height
        radius: 5
        Text{
            width: parent.width
            height: parent.height
            anchors.fill: parent
            anchors.margins: 2
            horizontalAlignment: Text.AlignHCenter
            verticalAlignment: Text.AlignVCenter
            text: "-"
        }
        MouseArea{
            anchors.fill: parent
            onClicked:{
                // --- Option 2: via registered type ---
                //myDataModel.decreaseTemperature(1)
                myDataModel.pressure--
            }
        }
    }
}
