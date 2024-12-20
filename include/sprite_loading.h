#include <tonc.h>
#ifndef SPR_LOADING_H
#define SPR_LOADING_H

#define MAX_OBJECTS 32

struct Object {
    u32 x;
    u16 y;
    u16 type;
    u16 attrib1;
    u16 attrib2;
    u16 attrib3;
    u16 attrib4;
};

struct ObjectSlot {
    u8 occupied;
    u8 activated;
    struct Object object;
};

enum ObjTypes {
    NONE,
    SHIP_PORTAL,
    CUBE_PORTAL,
    COL_TRIGGER,
    OBJ_COUNT
};

enum ColorChannels {
    COL1,
    COL2,
    COL3,
    COL4,
    BG,
    GROUND,
    OBJ,
    LINE,
    CHANNEL_COUNT  
};

extern struct Object gObject;
extern u32 *sprite_pointer;
extern struct ObjectSlot object_buffer[MAX_OBJECTS];


void load_next_object();
void display_objects();
void run_col_triggers();
void check_obj_collision(u32 index);
u32 is_colliding(u32 x1, u32 y1, u32 w1, u32 h1, u32 x2, u32 y2, u32 w2, u32 h2);
#endif