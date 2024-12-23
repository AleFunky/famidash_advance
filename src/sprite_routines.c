#include "main.h"
#include "sprite_loading.h"
#include "sprite_routines.h"
#include "physics_defines.h"
#include "color.h"

void ship_portal(struct ObjectSlot *objectSlot) {
    gamemode = SHIP;
    objectSlot->activated = TRUE;
}

void cube_portal(struct ObjectSlot *objectSlot) {
    gamemode = CUBE;
    objectSlot->activated = TRUE;
}

void blue_gravity_portal(struct ObjectSlot *objectSlot) {
    gravity_dir = 0;
    if (player_y_speed < -GRAVITY_PORTAL_SPEED_CAP) player_y_speed = -GRAVITY_PORTAL_SPEED_CAP; 
    objectSlot->activated = TRUE;
}

void yellow_gravity_portal(struct ObjectSlot *objectSlot) {
    gravity_dir = 1;
    if (player_y_speed > GRAVITY_PORTAL_SPEED_CAP) player_y_speed = GRAVITY_PORTAL_SPEED_CAP; 
    objectSlot->activated = TRUE;
}

void col_trigger(struct ObjectSlot *objectSlot) {
    struct Object col_trigger = objectSlot->object;
    
    // If the player is right of the horizontal center of the trigger, activate the color trigger
    if ((player_x >> 8) >= (col_trigger.x + 8)) {
        u32 frames = (col_trigger.attrib1 >> 3) + 1; // +1 because 0 = 1
        u32 channel = col_trigger.attrib1 & 0x7;

        u8 copy = col_trigger.attrib3 & 1;
        
        // Save variables into buffer
        switch (channel) {
            case BG:
                col_trigger_buffer[channel][COL_TRIG_BUFF_OLD_COLOR] = palette_buffer[0x00];
                break;
            case GROUND:
                col_trigger_buffer[channel][COL_TRIG_BUFF_OLD_COLOR] = palette_buffer[0x41];
                break;
            case OBJ:
                col_trigger_buffer[channel][COL_TRIG_BUFF_OLD_COLOR] = palette_buffer[0x09];
                break;
            case LINE:
                col_trigger_buffer[channel][COL_TRIG_BUFF_OLD_COLOR] = palette_buffer[0x48];
                break;
            case COL1:
            case COL2:
            case COL3:
            case COL4:
                col_trigger_buffer[channel][COL_TRIG_BUFF_OLD_COLOR] = palette_buffer[0x0D + (channel << 4)];
                break;
        }
        col_trigger_buffer[channel][COL_TRIG_BUFF_ACTIVE] = TRUE;
        if (copy) {
            u8 copied_channel = col_trigger.attrib3 >> 1;

            switch (copied_channel) {
                case BG:
                    col_trigger_buffer[channel][COL_TRIG_BUFF_NEW_COLOR] = palette_buffer[0x00];
                    break;
                case GROUND:
                    col_trigger_buffer[channel][COL_TRIG_BUFF_NEW_COLOR] = palette_buffer[0x41];
                    break;
                case OBJ:
                    col_trigger_buffer[channel][COL_TRIG_BUFF_NEW_COLOR] = palette_buffer[0x09];
                    break;
                case LINE:
                    col_trigger_buffer[channel][COL_TRIG_BUFF_NEW_COLOR] = palette_buffer[0x48];
                    break;
                case P1:
                    col_trigger_buffer[channel][COL_TRIG_BUFF_NEW_COLOR] = palette_buffer[0x105];
                    break;
                case P2:
                    col_trigger_buffer[channel][COL_TRIG_BUFF_NEW_COLOR] = palette_buffer[0x108];
                    break;
                case COL1:
                case COL2:
                case COL3:
                case COL4:
                    col_trigger_buffer[channel][COL_TRIG_BUFF_NEW_COLOR] = palette_buffer[0x0D + (channel << 4)];
                    break;
            }
        } else {
            col_trigger_buffer[channel][COL_TRIG_BUFF_NEW_COLOR] = col_trigger.attrib2;
        }
        col_trigger_buffer[channel][COL_TRIG_BUFF_TOTAL_FRAMES] = frames; // Total frames
        col_trigger_buffer[channel][COL_TRIG_BUFF_CURRENT_FRAMES] = 0;      // Current frame

        // Deoccupy slot
        objectSlot->occupied = FALSE;
    }
}

void yellow_orb(struct ObjectSlot *objectSlot) {
    if (player_buffering == ORB_BUFFER_READY) {
        s32 sign = gravity_dir ? 1 : -1;
        player_y_speed = YELLOW_ORB_JUMP_SPEED * sign;
        objectSlot->activated = TRUE;
        on_floor = FALSE;
        player_buffering = ORB_BUFFER_END;
    }
}

void yellow_pad(struct ObjectSlot *objectSlot) {
    s32 sign = gravity_dir ? 1 : -1;
    player_y_speed = YELLOW_PAD_JUMP_SPEED * sign;
    on_floor = FALSE;
    objectSlot->activated = TRUE;
}

void do_nothing(UNUSED struct ObjectSlot *objectSlot) {
    // No routine defined
}

const jmp_table routines_jump_table[] = {
    do_nothing,
    ship_portal,
    cube_portal,
    col_trigger,
    do_nothing,
    do_nothing,
    do_nothing,
    do_nothing,
    do_nothing,
    yellow_orb,
    yellow_pad,
    do_nothing,
    do_nothing,
    do_nothing,
    blue_gravity_portal,
    yellow_gravity_portal,
};

// In pixels
#define Object_Hitbox(name, hw, hh, hxoff, hyoff, center_x, center_y) {hw, hh, hxoff, hyoff, center_x, center_y},

const s16 obj_hitbox[][6] = {
    Object_Hitbox("NONE", 0, 0, 0, 0, 0, 0)
    Object_Hitbox("SHIP_PORTAL", 18, 46, -2, 1, 8, 24)
    Object_Hitbox("CUBE_PORTAL", 18, 46, -2, 1, 8, 24)
    Object_Hitbox("COL_TRIGGER", 0, 0, 0, 0, 0, 0)
    Object_Hitbox("BIG_BG_SPIKES", 0, 0, 0, 0, 0, 0)
    Object_Hitbox("MEDIUM_BG_SPIKES", 0, 0, 0, 0, 0, 0)
    Object_Hitbox("SMALL_BG_SPIKES", 0, 0, 0, 0, 0, 0)
    Object_Hitbox("TINY_BG_SPIKES", 0, 0, 0, 0, 0, 0)
    Object_Hitbox("BG_CHAIN", 0, 0, 0, 0, 0, 0)
    Object_Hitbox("YELLOW_ORB", 18, 18, -2, -2, 8, 8)
    Object_Hitbox("YELLOW_PAD", 14, 2, 1, 14, 8, 8)
    Object_Hitbox("MEDIUM_PULSING_CIRCLE", 0, 0, 0, 0, 0, 0)
    Object_Hitbox("SMALL_PULSING_CIRCLE", 0, 0, 0, 0, 0, 0)
    Object_Hitbox("LARGE_PULSING_CIRCLE", 0, 0, 0, 0, 0, 0)
    Object_Hitbox("BLUE_GRAVITY_PORTAL", 14, 40, 1, 4, 8, 24)
    Object_Hitbox("YELLOW_GRAVITY_PORTAL", 14, 40, 1, 4, 8, 24)
};

#undef Object_Hitbox