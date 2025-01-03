#include "includes.h"
const u16 *level_defines[][4] = {
   { stereomadness_l1_level_data, stereomadness_l2_level_data, stereomadness_spr_data, stereomadness_properties },
   { backontrack_l1_level_data, backontrack_l2_level_data, backontrack_spr_data, backontrack_properties },
   { polargeist_l1_level_data, polargeist_l2_level_data, polargeist_spr_data, polargeist_properties },
   { dryout_l1_level_data, dryout_l2_level_data, dryout_spr_data, dryout_properties },
   { baseafterbase_l1_level_data, baseafterbase_l2_level_data, baseafterbase_spr_data, baseafterbase_properties },
   { cantletgo_l1_level_data, cantletgo_l2_level_data, cantletgo_spr_data, cantletgo_properties },
   { jumper_l1_level_data, jumper_l2_level_data, jumper_spr_data, jumper_properties },
   { timemachine_l1_level_data, timemachine_l2_level_data, timemachine_spr_data, timemachine_properties },
   { cycles_l1_level_data, cycles_l2_level_data, cycles_spr_data, cycles_properties },
   { xstep_l1_level_data, xstep_l2_level_data, xstep_spr_data, xstep_properties },
   { test_l1_level_data, test_l2_level_data, test_spr_data, test_properties },
};
const u8 *level_names[] = {
   stereomadness_name,
   backontrack_name,
   polargeist_name,
   dryout_name,
   baseafterbase_name,
   cantletgo_name,
   jumper_name,
   timemachine_name,
   cycles_name,
   xstep_name,
   test_name,
};
