#pragma once

#include <tonc.h>

#include "memory.h"

// Defines indexes
#define L1_DATA_INDEX 0
#define L2_DATA_INDEX 1
#define SPRITE_DATA_INDEX 2
#define LEVEL_PROPERTIES_INDEX 3

// Properties indexes
#define BG_COLOR_INDEX 0
#define GROUND_COLOR_INDEX 1
#define COL1_COLOR_INDEX 2
#define COL2_COLOR_INDEX 3
#define COL3_COLOR_INDEX 4
#define COL4_COLOR_INDEX 5
#define OBJ_COLOR_INDEX 6
#define GAMEMODE_INDEX 7
#define SPEED_INDEX 8
#define LEVEL_HEIGHT_INDEX 9
#define LEVEL_WIDTH_INDEX 10
#define LEVEL_SONG_INDEX 11

#define LEVEL_NAME_LENGTH 12

#define LEVEL_DIFFICULTY 13

#define LEVEL_STARS_NUM 14

#define LEVEL_COINS_NUM 15

#define LEVEL_BACKGROUND_TYPE 16

#define LEVEL_GROUND_TYPE 17
// stereomadness
#define stereomadness_ID 0

#include "stereomadness/l1.h"
#include "stereomadness/l2.h"
#include "stereomadness/SP.h"
#include "stereomadness/properties.h"

// backontrack
#define backontrack_ID 1

#include "backontrack/l1.h"
#include "backontrack/l2.h"
#include "backontrack/SP.h"
#include "backontrack/properties.h"

// polargeist
#define polargeist_ID 2

#include "polargeist/l1.h"
#include "polargeist/l2.h"
#include "polargeist/SP.h"
#include "polargeist/properties.h"

// dryout
#define dryout_ID 3

#include "dryout/l1.h"
#include "dryout/l2.h"
#include "dryout/SP.h"
#include "dryout/properties.h"

// baseafterbase
#define baseafterbase_ID 4

#include "baseafterbase/l1.h"
#include "baseafterbase/l2.h"
#include "baseafterbase/SP.h"
#include "baseafterbase/properties.h"

// cantletgo
#define cantletgo_ID 5

#include "cantletgo/l1.h"
#include "cantletgo/l2.h"
#include "cantletgo/SP.h"
#include "cantletgo/properties.h"

// jumper
#define jumper_ID 6

#include "jumper/l1.h"
#include "jumper/l2.h"
#include "jumper/SP.h"
#include "jumper/properties.h"

// timemachine
#define timemachine_ID 7

#include "timemachine/l1.h"
#include "timemachine/l2.h"
#include "timemachine/SP.h"
#include "timemachine/properties.h"

// cycles
#define cycles_ID 8

#include "cycles/l1.h"
#include "cycles/l2.h"
#include "cycles/SP.h"
#include "cycles/properties.h"

// xstep
#define xstep_ID 9

#include "xstep/l1.h"
#include "xstep/l2.h"
#include "xstep/SP.h"
#include "xstep/properties.h"

// clutterfunk
#define clutterfunk_ID 10

#include "clutterfunk/l1.h"
#include "clutterfunk/l2.h"
#include "clutterfunk/SP.h"
#include "clutterfunk/properties.h"

// theoryofeverything
#define theoryofeverything_ID 11

#include "theoryofeverything/l1.h"
#include "theoryofeverything/l2.h"
#include "theoryofeverything/SP.h"
#include "theoryofeverything/properties.h"

// electromanadventures
#define electromanadventures_ID 12

#include "electromanadventures/l1.h"
#include "electromanadventures/l2.h"
#include "electromanadventures/SP.h"
#include "electromanadventures/properties.h"

// clubstep
#define clubstep_ID 13

#include "clubstep/l1.h"
#include "clubstep/l2.h"
#include "clubstep/SP.h"
#include "clubstep/properties.h"

// electrodynamix
#define electrodynamix_ID 14

#include "electrodynamix/l1.h"
#include "electrodynamix/l2.h"
#include "electrodynamix/SP.h"
#include "electrodynamix/properties.h"

// leveleasy
#define leveleasy_ID 15

#include "leveleasy/l1.h"
#include "leveleasy/l2.h"
#include "leveleasy/SP.h"
#include "leveleasy/properties.h"

// groundtospace
#define groundtospace_ID 16

#include "groundtospace/l1.h"
#include "groundtospace/l2.h"
#include "groundtospace/SP.h"
#include "groundtospace/properties.h"

// ultimatedestruction
#define ultimatedestruction_ID 17

#include "ultimatedestruction/l1.h"
#include "ultimatedestruction/l2.h"
#include "ultimatedestruction/SP.h"
#include "ultimatedestruction/properties.h"

// thenightmare
#define thenightmare_ID 18

#include "thenightmare/l1.h"
#include "thenightmare/l2.h"
#include "thenightmare/SP.h"
#include "thenightmare/properties.h"

// rose
#define rose_ID 19

#include "rose/l1.h"
#include "rose/l2.h"
#include "rose/SP.h"
#include "rose/properties.h"

// problematic
#define problematic_ID 20

#include "problematic/l1.h"
#include "problematic/l2.h"
#include "problematic/SP.h"
#include "problematic/properties.h"

// test
#define test_ID 21

#include "test/l1.h"
#include "test/l2.h"
#include "test/SP.h"
#include "test/properties.h"

// test2
#define test2_ID 22

#include "test2/l1.h"
#include "test2/l2.h"
#include "test2/SP.h"
#include "test2/properties.h"

// Mariometry
#define Mariometry_ID 23

#include "Mariometry/l1.h"
#include "Mariometry/l2.h"
#include "Mariometry/SP.h"
#include "Mariometry/properties.h"

#define LEVEL_COUNT 24
extern ROM_DATA const u16 *level_defines[][4];
extern ROM_DATA const u8 *level_names[];
