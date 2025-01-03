#pragma once

#include <tonc.h>
#include <maxmod.h>
#include "sprite_loading.h"
#include "sprite_routines.h"

#define MAX_LEVEL_HEIGHT 128
#define GROUND_HEIGHT MAX_LEVEL_HEIGHT - 4
#define LEVEL_BUFFER_WIDTH 32
#define LEVEL_LAYERS 2

typedef OBJ_ATTR OAM_SPR;
#define UNUSED __unused

#define ARM_CODE __attribute__((target("arm"), section(".iwram"), long_call))

extern OAM_SPR shadow_oam[128];
extern OBJ_AFFINE *obj_aff_buffer;
extern EWRAM_DATA u16 level_buffer[LEVEL_LAYERS][MAX_LEVEL_HEIGHT*LEVEL_BUFFER_WIDTH];
extern IWRAM_DATA COLOR palette_buffer[512];
extern EWRAM_DATA u16 rotation_buffer[NUM_ROT_SLOTS];

#define COL_TRIG_BUFF_ACTIVE 0
#define COL_TRIG_BUFF_OLD_COLOR 1
#define COL_TRIG_BUFF_NEW_COLOR 2
#define COL_TRIG_BUFF_TOTAL_FRAMES 3
#define COL_TRIG_BUFF_CURRENT_FRAMES 4

extern EWRAM_DATA u16 col_trigger_buffer[CHANNEL_COUNT][5];

extern u8 curr_column;
extern u8 curr_level_height;
extern u32 *level_pointer[2];

extern u64 scroll_x;
extern u64 scroll_y;

extern u32 target_scroll_y;

extern s8 scroll_y_dir;

extern u16 loaded_level_id;
extern u16 loaded_song_id;

#define NUM_CHANNELS 8

extern EWRAM_DATA u8 music_data[NUM_CHANNELS * (MM_SIZEOF_MODCH
                               +MM_SIZEOF_ACTCH
                               +MM_SIZEOF_MIXCH)
                               +MM_MIXLEN_31KHZ];

extern u8 debug_mode;

extern u8 paused;

enum UpdateFlags {
    UPDATE_NONE,
    UPDATE_OAM          = (1 << 0),
    CLEAR_OAM_BUFFER    = (1 << 1),
    UPDATE_VRAM         = (1 << 2),
    UPDATE_SCROLL       = (1 << 3),
};

#define UPDATE_ALL UPDATE_OAM | UPDATE_VRAM | UPDATE_SCROLL | CLEAR_OAM_BUFFER

extern u8 update_flags;

extern u32 global_timer;