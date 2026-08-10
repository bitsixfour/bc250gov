#pragma once

#include <cstdint>
#include <cstring>
#include <cmath>

namespace Codec {

inline uint32_t dec_uint32(uint32_t value) {
  return value;
}

inline uint32_t pack_uint32(uint32_t value) {
  return value;
}

inline uint32_t pack_uint16(uint16_t value) {
  return static_cast<uint32_t>(value);
}

inline uint32_t pack_float32(float value) {
  uint32_t packed = 0;
  static_assert(sizeof(packed) == sizeof(value));
  std::memcpy(&packed, &value, sizeof(packed));
  return packed;
}

inline uint32_t mv_vid(uint32_t millivolts) {
  const double volts = static_cast<double>(millivolts) / 1000.0;
  return static_cast<uint32_t>(std::round((1.55 - volts) / 0.00625));
}

inline uint32_t vid_mv(uint32_t vid) {
  const double volts = (static_cast<double>(vid) * -0.00625) + 1.55;
  return static_cast<uint32_t>(std::round(volts * 1000.0));
}

}  // namespace Codec
