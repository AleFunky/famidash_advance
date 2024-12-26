#include "main.h"
#include "physics_defines.h"

// Position variables, in subpixels
u64 player_x; // gota love giant levels
u64 player_y;

// Player dimensions, in pixels
u16 player_width;
u16 player_height;

// Speed variables, in subpixels/frame
s32 player_x_speed;
s32 player_y_speed;

// Relative position on screen in pixels
u16 relative_player_x;
u16 relative_player_y;

// Change of y speed
s16 gravity;

// Direction of the gravity. 0 : down, 1 : up
u8 gravity_dir;

// 0 : alive , 1 : death
u8 player_death;

// 0 : on air, 1 : on floor
u8 on_floor;

// 0 : not buffering, 1 : buffering
u8 player_buffering;

// Current player gamemode
u8 gamemode = CUBE;

// Cube rotation angle
u16 cube_rotation = 0;

// in subpixels
const u32 speed_constants[] = {
    SPEED_HALF, // x0.5
    SPEED_1x,   // x1
    SPEED_2x,   // x2
    SPEED_3x,    // x3
    SPEED_4x     // x4
};

// Current speed ID
u8 speed_id = SPEED_X1;


// Draw player
u8 x_offset;
u8 y_offset;


#define TOP_SCROLL_Y 0x2c
#define BOTTOM_SCROLL_Y SCREEN_HEIGHT-0x2c

void cube_gamemode();
void ship_gamemode();
void ball_gamemode();

void player_main() {    
    // Set player speed
    player_x_speed = speed_constants[speed_id];
    
    // This scrolls the screen on the x axis
    if (relative_player_x >= 0x50) {
        scroll_x += player_x_speed;
    }

    // This scrolls the screen on the y axis
    if (relative_player_y >= BOTTOM_SCROLL_Y && player_y_speed > 0) {
        scroll_y_dir = 1;
        scroll_y += player_y_speed;
    } else if (relative_player_y <= TOP_SCROLL_Y && player_y_speed < 0) { 
        scroll_y_dir = 0;
        scroll_y += player_y_speed;
    }

    if (key_held(KEY_A | KEY_UP)) {
        if (player_buffering == NO_ORB_BUFFER) {
            player_buffering = ORB_BUFFER_READY;
        }
    } else {
        player_buffering = NO_ORB_BUFFER;
    }
    
    // Gamemode specific routines
    switch (gamemode) {
        case CUBE:
            cube_gamemode();
            break;
        case SHIP:
            ship_gamemode();
            break;
        case BALL:
            ball_gamemode();
            break;
    }
    obj_aff_identity(&obj_aff_buffer[0]);

    obj_aff_rotate(&obj_aff_buffer[0], cube_rotation);
}

void cube_gamemode() {
    gravity = CUBE_GRAVITY;
    player_width = CUBE_WIDTH;
    player_height = CUBE_HEIGHT;

    s8 sign = gravity_dir ? -1 : 1;

    // Depending on which direction the gravity points, apply gravity and cap speed in one direction or in the other
    if (gravity_dir) {
        player_y_speed -= gravity;
        if (player_y_speed < -CUBE_MAX_Y_SPEED) player_y_speed = -CUBE_MAX_Y_SPEED;
    } else {
        player_y_speed += gravity;
        if (player_y_speed > CUBE_MAX_Y_SPEED) player_y_speed = CUBE_MAX_Y_SPEED;
    }
   
    // If on floor and holding A or UP, jump
    if (on_floor && key_held(KEY_A | KEY_UP)) {
        player_y_speed = -CUBE_JUMP_SPEED * sign;     
        player_buffering = ORB_BUFFER_END;
    }

    // If the cube is on the air, rotate, else, snap to nearest 
    if (!on_floor) {
        cube_rotation -= 0x500 * sign;
    } else {
        cube_rotation = (cube_rotation + 0x2000) & 0xC000;
    }

    on_floor = 0;

    for (s32 step = 0; step < NUM_STEPS - 1; step++) {
        // Apply quarter of speed
        // Update player x and y
        player_x += player_x_speed >> 2;
        player_y += player_y_speed >> 2;
        
        // Run collision
        collision_cube();

        // If player is dead, do not advance more quarter steps
        if (player_death) break;

        // Do collision with objects
       if (step & 1) do_collision_with_objects(FALSE);
    }
    
    // If player is dead, do not advance more quarter steps
    if (!player_death) {
        // Apply last quarter of speed
        // Update player x and y
        player_x += player_x_speed - ((player_x_speed >> 2) * 3);
        player_y += player_y_speed - ((player_y_speed >> 2) * 3);
    
        // Run collision
        collision_cube();

        if (!player_death) {
            // Do collision with objects
            do_collision_with_objects(TRUE);
        }
    }

    relative_player_x = (player_x - scroll_x) >> SUBPIXEL_BITS;
    relative_player_y = (player_y - scroll_y) >> SUBPIXEL_BITS;

    x_offset = (cube_rotation >= 0x6000 && cube_rotation < 0xe000 ? 9 : 8);
    y_offset = (cube_rotation >= 0x2000 && cube_rotation < 0xa000 ? 9 : 8);
    oam_metaspr(relative_player_x - x_offset, relative_player_y - y_offset, playerSpr, 0, 0);
}

void ship_gamemode() {
    player_width = SHIP_WIDTH;
    player_height = SHIP_HEIGHT;
    gravity = SHIP_GRAVITY;

    s8 sign = gravity_dir ? -1 : 1;

    if (key_held(KEY_A | KEY_UP)) {
        cube_rotation = (-(player_y_speed) >> (SUBPIXEL_BITS - 2)) * 0x380; 

        player_y_speed -= gravity * sign;
    } else {
        cube_rotation = (-(player_y_speed) >> (SUBPIXEL_BITS - 2)) * 0x380; 

        player_y_speed += gravity * sign;
    }
    
    player_y_speed = CLAMP(player_y_speed, -SHIP_MAX_Y_SPEED, SHIP_MAX_Y_SPEED);

    on_floor = 0;
    
    for (s32 step = 0; step < NUM_STEPS - 1; step++) {
        // Apply quarter of speed
        // Update player x and y
        player_x += player_x_speed >> 2;
        player_y += player_y_speed >> 2;
        
        // Run collision
        collision_ship();

        // If player is dead, do not advance more quarter steps
        if (player_death) break;

        // Do collision with objects
        if (step & 1) do_collision_with_objects(FALSE);
    }

    // If player is dead, do not advance more quarter steps
    if (!player_death) {
        // Apply last quarter of speed
        // Update player x and y
        player_x += player_x_speed - ((player_x_speed >> 2) * 3);
        player_y += player_y_speed - ((player_y_speed >> 2) * 3);
        
        // Run collision
        collision_ship();

        if (!player_death) {
            // Do collision with objects
            do_collision_with_objects(TRUE);
        }
    }

    relative_player_x = (player_x - scroll_x) >> SUBPIXEL_BITS;
    relative_player_y = (player_y - scroll_y) >> SUBPIXEL_BITS;

    x_offset = (cube_rotation >= 0x6000 && cube_rotation < 0xe000 ? 8 : 7);
    y_offset = (cube_rotation >= 0x2000 && cube_rotation < 0xa000 ? 8 : 7);

    // The GBA can't flip rotated sprites, so a separate sprite is needed
    if (gravity_dir) {
        oam_metaspr(relative_player_x - x_offset, relative_player_y - y_offset, shipFlippedSpr, 0, 0);
    } else {
        oam_metaspr(relative_player_x - x_offset, relative_player_y - y_offset, shipSpr, 0, 0);
    }
}

void ball_gamemode() {
    player_width = BALL_WIDTH;
    player_height = BALL_HEIGHT;
    gravity = BALL_GRAVITY;

    s8 sign = gravity_dir ? -1 : 1;

    cube_rotation -= 0x500 * sign;

    player_y_speed += gravity * sign;

    if (on_floor && player_buffering == ORB_BUFFER_READY) {
        gravity_dir ^= 1;
        player_y_speed = BALL_SWITCH_SPEED * -sign; 
        player_buffering = ORB_BUFFER_END;
    }
    
    player_y_speed = CLAMP(player_y_speed, -BALL_MAX_Y_SPEED, BALL_MAX_Y_SPEED);

    on_floor = 0;

    for (s32 step = 0; step < NUM_STEPS - 1; step++) {
        // Apply quarter of speed
        // Update player x and y
        player_x += player_x_speed >> 2;
        player_y += player_y_speed >> 2;
        
        // Run collision
        collision_ship();

        // If player is dead, do not advance more quarter steps
        if (player_death) break;

        // Do collision with objects
        if (step & 1) do_collision_with_objects(FALSE);
    }

    // If player is dead, do not advance more quarter steps
    if (!player_death) {
        // Apply last quarter of speed
        // Update player x and y
        player_x += player_x_speed - ((player_x_speed >> 2) * 3);
        player_y += player_y_speed - ((player_y_speed >> 2) * 3);
        
        // Run collision
        collision_ship();

        if (!player_death) {
            // Do collision with objects
            do_collision_with_objects(TRUE);
        }
    }

    relative_player_x = (player_x - scroll_x) >> SUBPIXEL_BITS;
    relative_player_y = (player_y - scroll_y) >> SUBPIXEL_BITS;

    oam_metaspr(relative_player_x - 8, relative_player_y - 8, ballSpr, 0, 0);
}