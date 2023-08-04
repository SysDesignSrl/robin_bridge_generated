#ifndef ROBIN_STRUCTS_H
#define ROBIN_STRUCTS_H
#include <cstdint>
struct CommonCommand
{
  uint8_t execute;
  uint8_t abort;
  int32_t id;
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
  char frame_id[81];
};
struct CameraMsg
{
  Header header;
  int32_t n_detections;
  int32_t suggested_step;
};
struct CommonFeedback
{
  uint8_t busy;
  uint8_t done;
  uint8_t aborted;
  uint8_t error;
  int32_t error_id;
};
struct PlcMsg
{
  Header header;
  uint8_t tube_detected;
};
#endif
