#include "metatiles.h"
#include "collision.h"

#define Metatile(name, tl, tr, bl, br, col) {tl, tr, bl, br, col},

#define H_FLIP 1
#define V_FLIP 1

// Goes like this TOP_LEFT, TOP_RIGHT, BOTTOM_LEFT, BOTTOM_RIGHT, COL_TYPE
SCR_ENTRY metatiles[][5] = {
    Metatile("AIR",            SE_BUILD(0x00, 0, 0, 0), SE_BUILD(0x00, 0, 0, 0), SE_BUILD(0x00, 0, 0, 0), SE_BUILD(0x00, 0, 0, 0), COL_NONE)
    Metatile("SPIKE_UP",       SE_BUILD(0x00, 0, 0, 0), SE_BUILD(0x00, 0, 0, 0), SE_BUILD(0x00, 0, 0, 0), SE_BUILD(0x00, 0, 0, 0), COL_NONE)
    Metatile("BASIC_BLOCK",    SE_BUILD(0x0e, 0, 0, 0), SE_BUILD(0x0f, 0, 0, 0), SE_BUILD(0x10, 0, 0, 0), SE_BUILD(0x11, 0, 0, 0), COL_ALL)
    
    Metatile("CHK_FULL",       SE_BUILD(0x01, 0, 0, 0),           SE_BUILD(0x01, 0, H_FLIP, 0),      SE_BUILD(0x01, 0, 0, V_FLIP),      SE_BUILD(0x01, 0, H_FLIP, V_FLIP), COL_ALL)
    Metatile("CHK_SIDE_UP",    SE_BUILD(0x02, 0, 0, 0),           SE_BUILD(0x02, 0, H_FLIP, 0),      SE_BUILD(0x03, 0, 0, 0),           SE_BUILD(0x03, 0, H_FLIP, 0),      COL_ALL)
    Metatile("CHK_SIDE_DOWN",  SE_BUILD(0x03, 0, 0, V_FLIP),      SE_BUILD(0x03, 0, H_FLIP, V_FLIP), SE_BUILD(0x02, 0, 0, V_FLIP),      SE_BUILD(0x02, 0, H_FLIP, V_FLIP), COL_ALL)
    Metatile("CHK_SIDE_LEFT",  SE_BUILD(0x04, 0, 0, 0),           SE_BUILD(0x05, 0, 0, 0),           SE_BUILD(0x04, 0, 0, V_FLIP),      SE_BUILD(0x05, 0, 0, V_FLIP),      COL_ALL)
    Metatile("CHK_SIDE_RIGHT", SE_BUILD(0x05, 0, H_FLIP, 0),      SE_BUILD(0x04, 0, H_FLIP, 0),      SE_BUILD(0x05, 0, H_FLIP, V_FLIP), SE_BUILD(0x04, 0, H_FLIP, V_FLIP), COL_ALL)
    Metatile("CHK_CORNER_TL",  SE_BUILD(0x06, 0, 0, 0),           SE_BUILD(0x02, 0, H_FLIP, 0),      SE_BUILD(0x04, 0, 0, V_FLIP),      SE_BUILD(0x07, 0, 0, 0),           COL_ALL)
    Metatile("CHK_CORNER_TR",  SE_BUILD(0x02, 0, 0, 0),           SE_BUILD(0x06, 0, H_FLIP, 0),      SE_BUILD(0x07, 0, H_FLIP, 0),      SE_BUILD(0x04, 0, H_FLIP, V_FLIP), COL_ALL)
    Metatile("CHK_CORNER_BL",  SE_BUILD(0x04, 0, 0, 0),           SE_BUILD(0x07, 0, 0, V_FLIP),      SE_BUILD(0x06, 0, 0, V_FLIP),      SE_BUILD(0x02, 0, H_FLIP, V_FLIP), COL_ALL)
    Metatile("CHK_CORNER_BR",  SE_BUILD(0x07, 0, H_FLIP, V_FLIP), SE_BUILD(0x04, 0, H_FLIP, 0),      SE_BUILD(0x02, 0, 0, V_FLIP),      SE_BUILD(0x06, 0, H_FLIP, V_FLIP), COL_ALL)
    Metatile("CHK_CRN_INS_TL", SE_BUILD(0x08, 0, 0, 0),           SE_BUILD(0x05, 0, 0, 0),           SE_BUILD(0x03, 0, 0, 0),           SE_BUILD(0x09, 0, 0, 0),           COL_ALL)
    Metatile("CHK_CRN_INS_TR", SE_BUILD(0x05, 0, H_FLIP, 0),      SE_BUILD(0x08, 0, H_FLIP, 0),      SE_BUILD(0x09, 0, H_FLIP, 0),      SE_BUILD(0x03, 0, H_FLIP, 0),      COL_ALL)
    Metatile("CHK_CRN_INS_BL", SE_BUILD(0x03, 0, 0, V_FLIP),      SE_BUILD(0x09, 0, 0, V_FLIP),      SE_BUILD(0x08, 0, 0, V_FLIP),      SE_BUILD(0x05, 0, 0, V_FLIP),      COL_ALL)
    Metatile("CHK_CRN_INS_BR", SE_BUILD(0x09, 0, H_FLIP, V_FLIP), SE_BUILD(0x03, 0, H_FLIP, V_FLIP), SE_BUILD(0x05, 0, H_FLIP, V_FLIP), SE_BUILD(0x08, 0, H_FLIP, V_FLIP), COL_ALL)
    Metatile("CHK_DB_CRN_TOP", SE_BUILD(0x06, 0, 0, 0),           SE_BUILD(0x06, 0, H_FLIP, 0),      SE_BUILD(0x04, 0, 0, V_FLIP),      SE_BUILD(0x04, 0, H_FLIP, V_FLIP), COL_ALL)
    Metatile("CHK_DB_CRN_BOT", SE_BUILD(0x04, 0, 0, 0),           SE_BUILD(0x04, 0, H_FLIP, 0),      SE_BUILD(0x06, 0, 0, V_FLIP),      SE_BUILD(0x06, 0, H_FLIP, V_FLIP), COL_ALL)
    Metatile("CHK_DB_CRN_LFT", SE_BUILD(0x06, 0, 0, 0),           SE_BUILD(0x02, 0, H_FLIP, 0),      SE_BUILD(0x06, 0, 0, V_FLIP),      SE_BUILD(0x02, 0, H_FLIP, V_FLIP), COL_ALL)
    Metatile("CHK_DB_CRN_RGT", SE_BUILD(0x02, 0, 0, 0),           SE_BUILD(0x06, 0, H_FLIP, 0),      SE_BUILD(0x02, 0, 0, V_FLIP),      SE_BUILD(0x06, 0, H_FLIP, V_FLIP), COL_ALL)
    Metatile("CHK_DB_SIDE_V",  SE_BUILD(0x04, 0, 0, 0),           SE_BUILD(0x04, 0, H_FLIP, 0),      SE_BUILD(0x04, 0, 0, V_FLIP),      SE_BUILD(0x04, 0, H_FLIP, V_FLIP), COL_ALL)
    Metatile("CHK_DB_SIDE_H",  SE_BUILD(0x02, 0, 0, 0),           SE_BUILD(0x02, 0, H_FLIP, 0),      SE_BUILD(0x02, 0, 0, V_FLIP),      SE_BUILD(0x02, 0, H_FLIP, V_FLIP), COL_ALL)
    Metatile("CHK_FILLER",     SE_BUILD(0x0a, 0, 0, 0),           SE_BUILD(0x0a, 0, H_FLIP, 0),      SE_BUILD(0x0a, 0, 0, V_FLIP),      SE_BUILD(0x0a, 0, H_FLIP, V_FLIP), COL_NONE)
    
    Metatile("SPIKE_DOWN",         SE_BUILD(0x00, 0, 0, 0), SE_BUILD(0x00, 0, 0, 0), SE_BUILD(0x00, 0, 0, 0), SE_BUILD(0x00, 0, 0, 0), COL_NONE)
    Metatile("SPIKE_RIGHT",        SE_BUILD(0x00, 0, 0, 0), SE_BUILD(0x00, 0, 0, 0), SE_BUILD(0x00, 0, 0, 0), SE_BUILD(0x00, 0, 0, 0), COL_NONE)
    Metatile("SPIKE_LEFT",         SE_BUILD(0x00, 0, 0, 0), SE_BUILD(0x00, 0, 0, 0), SE_BUILD(0x00, 0, 0, 0), SE_BUILD(0x00, 0, 0, 0), COL_NONE)
    Metatile("SMALL_SPIKE_UP",     SE_BUILD(0x00, 0, 0, 0), SE_BUILD(0x00, 0, 0, 0), SE_BUILD(0x00, 0, 0, 0), SE_BUILD(0x00, 0, 0, 0), COL_NONE)
    Metatile("SMALL_SPIKE_DOWN",   SE_BUILD(0x00, 0, 0, 0), SE_BUILD(0x00, 0, 0, 0), SE_BUILD(0x00, 0, 0, 0), SE_BUILD(0x00, 0, 0, 0), COL_NONE)
    Metatile("SMALL_SPIKE_RIGHT",  SE_BUILD(0x00, 0, 0, 0), SE_BUILD(0x00, 0, 0, 0), SE_BUILD(0x00, 0, 0, 0), SE_BUILD(0x00, 0, 0, 0), COL_NONE)
    Metatile("SMALL_SPIKE_LEFT",   SE_BUILD(0x00, 0, 0, 0), SE_BUILD(0x00, 0, 0, 0), SE_BUILD(0x00, 0, 0, 0), SE_BUILD(0x00, 0, 0, 0), COL_NONE)
    Metatile("GROUND_SPIKE_UP",    SE_BUILD(0x00, 0, 0, 0), SE_BUILD(0x00, 0, 0, 0), SE_BUILD(0x00, 0, 0, 0), SE_BUILD(0x00, 0, 0, 0), COL_NONE)
    Metatile("GROUND_SPIKE_DOWN",  SE_BUILD(0x00, 0, 0, 0), SE_BUILD(0x00, 0, 0, 0), SE_BUILD(0x00, 0, 0, 0), SE_BUILD(0x00, 0, 0, 0), COL_NONE)
    Metatile("GROUND_SPIKE_RIGHT", SE_BUILD(0x00, 0, 0, 0), SE_BUILD(0x00, 0, 0, 0), SE_BUILD(0x00, 0, 0, 0), SE_BUILD(0x00, 0, 0, 0), COL_NONE)
    Metatile("GROUND_SPIKE_LEFT",  SE_BUILD(0x00, 0, 0, 0), SE_BUILD(0x00, 0, 0, 0), SE_BUILD(0x00, 0, 0, 0), SE_BUILD(0x00, 0, 0, 0), COL_NONE)
    Metatile("MEDIUM_SPIKE_UP",    SE_BUILD(0x00, 0, 0, 0), SE_BUILD(0x00, 0, 0, 0), SE_BUILD(0x00, 0, 0, 0), SE_BUILD(0x00, 0, 0, 0), COL_NONE)
    Metatile("MEDIUM_SPIKE_DOWN",  SE_BUILD(0x00, 0, 0, 0), SE_BUILD(0x00, 0, 0, 0), SE_BUILD(0x00, 0, 0, 0), SE_BUILD(0x00, 0, 0, 0), COL_NONE)
    Metatile("MEDIUM_SPIKE_RIGHT", SE_BUILD(0x00, 0, 0, 0), SE_BUILD(0x00, 0, 0, 0), SE_BUILD(0x00, 0, 0, 0), SE_BUILD(0x00, 0, 0, 0), COL_NONE)
    Metatile("MEDIUM_SPIKE_LEFT",  SE_BUILD(0x00, 0, 0, 0), SE_BUILD(0x00, 0, 0, 0), SE_BUILD(0x00, 0, 0, 0), SE_BUILD(0x00, 0, 0, 0), COL_NONE)
    
    Metatile("CHK_CORNER_TL",  SE_BUILD(0x0B, 0, 0, 0),           SE_BUILD(0x02, 0, H_FLIP, 0), SE_BUILD(0x04, 0, 0, V_FLIP), SE_BUILD(0x07, 0, 0, 0),           COL_NONE)
    Metatile("CHK_CORNER_TR",  SE_BUILD(0x02, 0, 0, 0),           SE_BUILD(0x0B, 0, H_FLIP, 0), SE_BUILD(0x07, 0, H_FLIP, 0), SE_BUILD(0x04, 0, H_FLIP, V_FLIP), COL_NONE)
    Metatile("CHK_CORNER_BL",  SE_BUILD(0x04, 0, 0, 0),           SE_BUILD(0x07, 0, 0, V_FLIP), SE_BUILD(0x0B, 0, 0, V_FLIP), SE_BUILD(0x02, 0, H_FLIP, V_FLIP), COL_NONE)
    Metatile("CHK_CORNER_BR",  SE_BUILD(0x07, 0, H_FLIP, V_FLIP), SE_BUILD(0x04, 0, H_FLIP, 0), SE_BUILD(0x02, 0, 0, V_FLIP), SE_BUILD(0x0B, 0, H_FLIP, V_FLIP), COL_NONE)
    
    Metatile("BASIC_BLOCK_DARK",    SE_BUILD(0x26, 0, 0, 0), SE_BUILD(0x27, 0, 0, 0), SE_BUILD(0x28, 0, 0, 0), SE_BUILD(0x29, 0, 0, 0), COL_ALL)
    
};