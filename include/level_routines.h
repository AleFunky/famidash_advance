#include <tonc.h>

extern s32 seam_x;
extern s32 seam_y;

extern u8 decompressed_column;

void decompress_first_screen();
void load_level(u32 level_ID);
void screen_scroll_load();
void reset_level();

void fade_out();
void fade_in();
void fade_in_level();

void scroll_screen_vertically();
void set_target_y_scroll(u32 object_y);