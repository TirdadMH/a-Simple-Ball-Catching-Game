#pragma once

class Panel // this class is for the panel.
{
private: // these are X and Y axis of the panel.
    int Panel_x_Axis;
    int Panel_y_Axis;
    int Original_Panel_x_Axis;
    int Original_Panel_y_Axis;

public:
    Panel(int PXA, int PYA) // constructor Function for the panel.
    {
        Panel_x_Axis = PXA;
        Panel_y_Axis = PYA;
        Original_Panel_x_Axis = PXA;
        Original_Panel_y_Axis = PYA;
    }
    inline void ResetPanel() // this function resets the panel to it's original location.
    {
        Panel_x_Axis = Original_Panel_x_Axis;
        Panel_y_Axis = Original_Panel_y_Axis;
    }
    inline int getPX() // gets X axis of the panel.
    {
        return Panel_x_Axis;
    }
    inline int getPY() // gets Y axis of the panel.
    {
        return Panel_y_Axis;
    }
    inline void PanelMoveRight() // this function moves the panel to right.
    {
        Panel_x_Axis += 3;
    }
    inline void PanelMoveLeft() // this function moves the panel to left.
    {
        Panel_x_Axis -= 3;
    }
};