#pragma once

// Purpose: VST (value semantic type) modeling OUCH 'SystemEventMessage'
//
// Exception Policy:
//    Exception free
//
// MT Safety:
//    const MT safe only
// 

#include <ouch_text_sizes.h>

#include <iostream>

#include <string.h>
#include <sys/types.h>

namespace OUCH {

#pragma pack(push,1)
struct SystemEventMessage {
  // DATA
  u_int16_t   d_messageLength;
  int8_t      d_packeType;
  int8_t      d_messageType;
  u_int64_t   d_timestamp;
  int8_t      d_enumeration;

  // CREATORS
  SystemEventMessage();
    // Construct SystemEventMessage object with all members set 0

  SystemEventMessage(const SystemEventMessage& other) = default;
    // Create a SystemEventMessage object holding a copy of specified 'other'.
    // Note that assignment to self is not detected, because copying a few
    // fields to self is fast, and idempotent.

  ~SystemEventMessage() = default;
    // Destroy this object

  // MANIPULATORS
  SystemEventMessage& operator=(const SystemEventMessage& rhs) = default;
    // Create and return SystemEventMessage object which is a copy of specified
    // 'rhs'. Note that assignment to self is not detected, because copying two
    // fields to self is fast, and idempotent.

  // ASPECTS
  std::ostream& print(std::ostream& stream) const;
    // Pretty print this object into specified 'stream' returning 'stream'
};
#pragma pack(pop)

// FREE OPERATORS
std::ostream& operator<<(std::ostream& stream, const SystemEventMessage& object);
  // Pretty print specfied 'object' in specified 'stream' returning 'stream'

// INLINE DEFINITIONS
// CREATORS
inline
SystemEventMessage::SystemEventMessage() {
  memset(this, 0, sizeof(SystemEventMessage));
}

// INLINE DEFINITIONS
// FREE OPERATORS
inline
std::ostream& operator<<(std::ostream& stream, const SystemEventMessage& object) {
  return object.print(stream);
}

} // namespace OUCH
