#include <tonc.h>

#pragma once

#define COL_TRIGGER_ATTRIB1_CHANNEL_MASK 0b111
#define COL_TRIGGER_ATTRIB1_FRAMES_MASK 0b1111111111111000
#define COL_TRIGGER_ATTRIB1_FRAMES_SHIFT 3

#define COL_TRIGGER_ROT_VAR_TOUCH_MASK 0b1

typedef void (*jmp_table)();
extern const jmp_table routines_jump_table[];
extern const s16 obj_hitbox[][6];

enum ObjTypes {
    NONE,

    SHIP_PORTAL,
    CUBE_PORTAL,

    COL_TRIGGER,
    BIG_BG_SPIKES,
    MEDIUM_BG_SPIKES,
    SMALL_BG_SPIKES,
    TINY_BG_SPIKES,
    BG_CHAINS,

    YELLOW_ORB,
    YELLOW_PAD,

    MEDIUM_PULSING_CIRCLE,
    SMALL_PULSING_CIRCLE,
    LARGE_PULSING_CIRCLE,
    
    BLUE_GRAVITY_PORTAL,
    YELLOW_GRAVITY_PORTAL,

    BLUE_ORB,
    BLUE_PAD,

    PINK_ORB,
    PINK_PAD,

    PULSING_CIRCLE,
    PULSING_CIRCUNFERENCE,
    PULSING_DIAMOND,
    PULSING_STAR,
    BIG_BG_CLOUDS,
    SMALL_BG_CLOUDS,

    BALL_PORTAL,

    PULSING_SQUARE,

    MINI_PORTAL,
    BIG_PORTAL,

    SPIKE_V,
    SPIKE_H,
    HALF_SPIKE_V,
    HALF_SPIKE_H,
    MEDIUM_SPIKE_V,
    MEDIUM_SPIKE_H,
    GROUND_SPIKE_V,
    GROUND_SPIKE_H,
    GROUND_WAVY_SPIKE_V,
    GROUND_WAVY_SPIKE_H,

    BIG_SAW,
    MEDIUM_SAW,
    SMALL_SAW,

    BASIC_BLOCK_OBJ,
    BASIC_SLAB_OBJ,

    ORANGE_MIRROR_PORTAL,
    BLUE_MIRROR_PORTAL,

    BIG_SAW_DECO,
    MEDIUM_SAW_DECO,
    SMALL_SAW_DECO,
    TINY_SAW_DECO,

    PULSING_NOTE,

    SPEED_PORTAL_HALF,
    SPEED_PORTAL_1x,
    SPEED_PORTAL_2x,
    SPEED_PORTAL_3x,
    SPEED_PORTAL_4x,

    UFO_PORTAL,

    BIG_BG_SQUARES,
    MEDIUM_BG_SQUARES,
    SMALL_BG_SQUARES,

    PULSING_ARROW,
    PULSING_EXCLAMATION,
    PULSING_INTERROGATION,

    GROUND_BUSH_SPIKE_1_V,
    GROUND_BUSH_SPIKE_2_V,
    GROUND_BUSH_SPIKE_3_V,
    GROUND_BUSH_SPIKE_4_V,
    GROUND_BUSH_SPIKE_1_H,
    GROUND_BUSH_SPIKE_2_H,
    GROUND_BUSH_SPIKE_3_H,
    GROUND_BUSH_SPIKE_4_H,

    ORANGE_DUAL_PORTAL,
    BLUE_DUAL_PORTAL,

    BIG_CIRCUNFERENCE_SAW_DECO,
    MED_CIRCUNFERENCE_SAW_DECO,
    SMA_CIRCUNFERENCE_SAW_DECO,
    
    SMALL_BG_CHAINS,
    SMALL_WIDE_BG_CHAINS,
    BIG_WIDE_BG_CHAINS,

    BIG_CLOUD,
    MEDIUM_CLOUD,
    SMALL_CLOUD,

    BUSH_DECO_1,
    BUSH_DECO_2,
    BUSH_DECO_3,
    BUSH_DECO_4,
    BUSH_DECO_5,
    BUSH_DECO_6,

    COIN,

    // 1.6 

    PULSING_HEARTH,

    BIG_DECO_TRIANGLE,
    MEDIUM_DECO_TRIANGLE,
    SMALL_DECO_TRIANGLE,
    
    BIG_CIRCLE_SAW_DECO,
    MEDIUM_CIRCLE_SAW_DECO,
    SMALL_CIRCLE_SAW_DECO,

    BIG_OUTLINE_SAW,
    MEDIUM_OUTLINE_SAW,
    SMALL_OUTLINE_SAW,

    BIG_SPIKE_SAW_DECO,
    MEDIUM_SPIKE_SAW_DECO,
    SMALL_SPIKE_SAW_DECO,

    DIAMOND_BG_CHAINS,

    ALT_BIG_OUTLINE_SAW,
    ALT_MEDIUM_OUTLINE_SAW,
    ALT_SMALL_OUTLINE_SAW,

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
    CHANNEL_COUNT,
    P1 = CHANNEL_COUNT,
    P2,
    TOTAL_CHANNEL_COUNT  
};
