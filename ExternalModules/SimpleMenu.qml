import QtQuick 2.15
//import SimpleMenuModel 1.0

Item {
    id: root

    property real xPos: 0
    property real yPos: 0

    // Instantiable c++ type
    /*SimpleMenuModel{
        id: mySimpleMenuModel
    }*/

    Rectangle
    {
        x: root.xPos
        y: root.yPos
        width: 100
        height: 100
        color: "azure"
        radius: 12
    }
}
