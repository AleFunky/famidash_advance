#define ICON_COUNT_CUBES 44
#define ICON_COUNT_SHIPS 9
#define ICON_COUNT_BALLS 14
#define ICON_COUNT_UFOS 8
#define ICON_COUNT_WAVES 16

#define ICONS_COLUMNS 7
#define ICONS_ROWS 2
#define ICONS_PER_PAGE (ICONS_COLUMNS * ICONS_ROWS)

#define ICON_X 46
#define ICON_Y 101

#define ICON_SIZE 16
#define ICON_MARGIN 6
#define ICON_STEP (ICON_SIZE + ICON_MARGIN)

#define VRAM_ICON_OFFSET 4

#define SELECTED_ICON_X 104
#define SELECTED_ICON_Y 32

#define ICON_KIT_SELECTION_INDEX 0x60

#define ICON_TAB_X 10
#define ICON_TAB_Y 9

#define PALETTE_KIT_ICONS_WIDTH (((GAMEMODE_COUNT - 1) * ICON_STEP) + ICON_SIZE)

#define PALETTE_KIT_ICONS_X (SCREEN_WIDTH/2 - (PALETTE_KIT_ICONS_WIDTH / 2))
#define PALETTE_KIT_ICONS_Y 40

#define PALETTE_KIT_SELECTION_X 40
#define PALETTE_KIT_SELECTION_Y 68

#define PALETTE_KIT_BUTTON_X 136
#define PALETTE_KIT_BUTTON_Y 16
#define PALETTE_KIT_BUTTON_ID 1012

#define PALETTE_KIT_COL1 0
#define PALETTE_KIT_COL2 1
#define PALETTE_KIT_GLOW 2

#define NUM_COLORS (sizeof(palette_kit_colors) / sizeof(COLOR))

extern const COLOR palette_kit_colors[112];

void icon_kit_loop();
