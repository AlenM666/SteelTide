#include "constants.h"


// movment constants
float Constants::GRAVITY = 9.81f;
float Constants::MAX_SPEED = 20.0f;
float Constants::CROUCH_SPEED = 5.0f;
float Constants::JUMP_FORCE = 12.0f;
float Constants::MAX_ACCELERATION = 150.0f;

// ground drag
float Constants::FRICTION = 0.86f;

// increase air drag, increase strafing speed
float Constants::AIR_DRAG = 0.98f;

// responcevnis to turn movment direction to look direction
float Constants::CONTROL = 15.0f;
float Constants::CROUCH_HEIGHT = 0.0f;
float Constants::STAND_HEIGHT = 1.0f;
float Constants::BOTTOM_HEIGHT = 0.5f;

int Constants::NORMALIZE_INPUT = 0;
