#ifndef ROBIN_STRUCTS_H
#define ROBIN_STRUCTS_H
#include <cstdint>
struct CommonCommand
{
  uint8_t execute;
  uint8_t abort;
  int32_t id;
};
struct CommonFeedback
{
  uint8_t busy;
  uint8_t done;
  uint8_t aborted;
  uint8_t error;
  int32_t error_id;
};
#endif
