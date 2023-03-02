#pragma once

// Purpose: VST (value semantic type) modeling OUCH 'CanceledEventMessage'
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
struct CanceledEventMessage {
  // DATA
  u_int16_t   d_messageLength;
  int8_t      d_packeType;
  int8_t      d_messageType;
  u_int64_t   d_timestamp;
  int8_t      d_orderToken[TextSize::kMAX_ORDER_TOKEN_SIZE];
  u_int16_t   d_decrementShares;
  int8_t      d_side;
  int8_t      d_reason;

  // CREATORS
  CanceledEventMessage();
    // Construct Header object with all members set 0

  CanceledEventMessage(const CanceledEventMessage& other);
    // Create a CanceledEventMessage object holding a copy of specified 'other'.

  ~CanceledEventMessage() = default;
    // Destroy this object

  // MANIPULATORS
  CanceledEventMessage& operator=(const CanceledEventMessage& rhs);
    // Create and return Header object which is a copy of specified 'rhs'  

  // ASPECTS
  std::ostream& print(std::ostream& stream) const;
    // Pretty print this object into specified 'stream' returning 'stream'
};
#pragma pack(pop)

// FREE OPERATORS
std::ostream& operator<<(std::ostream& stream, const CanceledEventMessage& object);
  // Pretty print specfied 'object' in specified 'stream' returning 'stream'

// INLINE DEFINITIONS
// CREATORS
inline
CanceledEventMessage::CanceledEventMessage() {
  memset(this, 0, sizeof(CanceledEventMessage));
}

inline
CanceledEventMessage::CanceledEventMessage(const CanceledEventMessage& other) {
  if (&other != this) {
    memcpy(this, &other, sizeof(CanceledEventMessage));
  }
}

// INLINE DEFINITIONS
// MANIPULATORS
inline
CanceledEventMessage& CanceledEventMessage::operator=(const CanceledEventMessage& rhs) {
  if (&rhs != this) {
    memcpy(this, &rhs, sizeof(CanceledEventMessage));
  }
  return *this;
}

// INLINE DEFINITIONS
// FREE OPERATORS
inline
std::ostream& operator<<(std::ostream& stream, const CanceledEventMessage& object) {
  return object.print(stream);
}

} // namespace OUCH
