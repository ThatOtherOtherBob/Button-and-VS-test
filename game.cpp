#include "game.hpp"
#include "zz1.hpp"

using namespace blit;

///////////////////////////////////////////////////////////////////////////
//
// init()
//
// setup your game here
//
void init() {
    set_screen_mode(ScreenMode::hires);
}

std::string message = "Hit buttons:";

///////////////////////////////////////////////////////////////////////////
//
// render(time)
//
// This function is called to perform rendering of the game. time is the 
// amount if milliseconds elapsed since the start of your game
//
void render(uint32_t time) {

    // clear the screen -- screen is a reference to the frame buffer and can be used to draw all things with the 32blit
    screen.clear();

    // draw some text at the top of the screen
    screen.alpha = 255;
    screen.mask = nullptr;
    screen.pen = Pen(255, 255, 255);
    screen.rectangle(Rect(0, 0, 320, 14));
    screen.pen = Pen(0, 0, 0);
    screen.text(message, minimal_font, Point(5, 4));
}

ButtonHandler bh;

///////////////////////////////////////////////////////////////////////////
//
// update(time)
//
// This is called to update your game state. time is the 
// amount if milliseconds elapsed since the start of your game
//
void update(uint32_t time) {
    for (ButtonEvents event : bh.UpdateStates(blit::buttons))
        switch (event)
        {
        case Up_Pressed:
            message += "^";
            break;
        case Down_Pressed:
            message += "V";
            break;
        case Left_Pressed:
            message += "<";
            break;
        case Right_Pressed:
            message += ">";
            break;
        case A_Pressed:
            message += "A";
            break;
        case B_Pressed:
            message += "B";
            break;
        case X_Pressed:
            message += "X";
            break;
        case Y_Pressed:
            message += "Y";
            break;
        case Home_Pressed:
            message += "H";
            break;
        case Menu_Pressed:
            message += "M";
            break;
        case Stick_Pressed:
            message += "S";
            break;
        }
}