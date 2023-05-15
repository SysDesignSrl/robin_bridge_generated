#ifndef ROBIN_STRUCTS_H
#define ROBIN_STRUCTS_H
#include <cstdint>
struct CommonCommand
{
  uint8_t execute;
  uint8_t abort;
  int32_t id;
};
struct PalletizingOptions
{
  char tool_name[81];
  char object_name[81];
  double object_weight;
  char pattern_file[256];
  char transform_name[81];
};
struct CommonFeedback
{
  uint8_t busy;
  uint8_t done;
  uint8_t aborted;
  uint8_t error;
  int32_t error_id;
};
struct Time
{
  uint32_t secs;
  uint32_t nsecs;
};
struct Header
{
  uint32_t seq;
  Time stamp;
  char frame_id[84];
};
struct JointState
{
  Header header;
  char name[20][81];
  double position[20];
  double velocity[20];
  double effort[20];
};
#endif
