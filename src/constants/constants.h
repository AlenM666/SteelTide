#pragma once


class Constants 
{

    // movment constants
    static float GRAVITY;
    static float MAX_SPEED;
    static float CROUCH_SPEED;
    static float JUMP_FORCE;
    static float MAX_ACCELERATION;

    // ground drag
    static float FRICTION;

    // increase air drag, increase strafing speed
    static float AIR_DRAG;

    // responcevnis to turn movment direction to look direction
    static float CONTROL;
    static float CROUCH_HEIGHT;
    static float STAND_HEIGHT;
    static float BOTTOM_HEIGHT;;

    static int NORMALIZE_INPUT;
};
