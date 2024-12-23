#pragma once

#include <tonc.h>

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

#define LEVEL_COUNT 3
extern const u16 *level_defines[][4];
extern const u8 *level_names[];
