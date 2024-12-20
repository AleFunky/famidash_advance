#include <tonc.h>

#define MAX_LEVEL_HEIGHT 128
#define GROUND_HEIGHT MAX_LEVEL_HEIGHT - 4
#define LEVEL_BUFFER_WIDTH 32
#define LEVEL_LAYERS 2

typedef OBJ_ATTR OAM_SPR;
#define UNUSED __unused

extern OAM_SPR shadow_oam[128];
extern OBJ_AFFINE *obj_aff_buffer;
extern EWRAM_DATA u16 level_buffer[LEVEL_LAYERS][MAX_LEVEL_HEIGHT*LEVEL_BUFFER_WIDTH];
extern EWRAM_DATA COLOR palette_buffer[512];

extern u8 curr_column;
extern u8 curr_level_height;
extern u16 *level_pointer[2];

extern u64 scroll_x;
extern u32 scroll_y;

extern s8 scroll_y_dir;