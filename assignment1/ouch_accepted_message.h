#pragma once

// Purpose: VST (value semantic type) modeling OUCH 'AcceptedEventMessage'
//
// Exception Policy:
//    Exception free
//
// MT Safety:
//    const MT safe only
// 

#include <ouch_text_sizes.h>

#include <string.h>
#include <sys/types.h>

#include <iostream>

namespace OUCH {

#pragma pack(push,1)
struct AcceptedEventMessage {
  // DATA
  u_int16_t   d_messageLength;
  int8_t      d_packeType;
  int8_t      d_messageType;
  u_int64_t   d_timestamp;
  int8_t      d_text[TextSize::kMAX_TEXT_SIZE];
  int8_t      d_side;
  u_int32_t   d_shares;
  int8_t      d_symbol[TextSize::kMAX_SYMBOL_SIZE];
  u_int32_t   d_price;                      // units of x10,000
  u_int32_t   d_timeInForce;
  int8_t      d_firm[TextSize::kMAX_FIRM_SIZE];
  int8_t      d_display;
  u_int32_t   d_orderReferenceNumber;
  int8_t      d_orderCapacity;
  int8_t      d_interMarketSweep;
  u_int32_t   d_minimumQuantity;
  int8_t      d_crossType;
  int8_t      d_orderState;

  // CREATORS
  AcceptedEventMessage();
    // Construct Header object with all members set 0

  AcceptedEventMessage(const AcceptedEventMessage& other);
    // Create a AcceptedEventMessage object holding a copy of specified 'other'.

  ~AcceptedEventMessage() = default;
    // Destroy this object

  // MANIPULATORS
  AcceptedEventMessage& operator=(const AcceptedEventMessage& rhs);
    // Create and return Header object which is a copy of specified 'rhs'  

  // ASPECTS
  std::ostream& print(std::ostream& stream) const;
    // Pretty print this object into specified 'stream' returning 'stream'
};
#pragma pack(pop)

// FREE OPERATORS
std::ostream& operator<<(std::ostream& stream, const AcceptedEventMessage& object);
  // Pretty print specfied 'object' in specified 'stream' returning 'stream'

// INLINE DEFINITIONS
// CREATORS
inline
AcceptedEventMessage::AcceptedEventMessage() {
  memset(this, 0, sizeof(AcceptedEventMessage));
}

inline
AcceptedEventMessage::AcceptedEventMessage(const AcceptedEventMessage& other) {
  if (&other != this) {
    memcpy(this, &other, sizeof(AcceptedEventMessage));
  }
}

// INLINE DEFINITIONS
// MANIPULATORS
inline
AcceptedEventMessage& AcceptedEventMessage::operator=(const AcceptedEventMessage& rhs) {
  if (&rhs != this) {
    memcpy(this, &rhs, sizeof(AcceptedEventMessage));
  }
  return *this;
}

// INLINE DEFINITIONS
// FREE OPERATORS
inline
std::ostream& operator<<(std::ostream& stream, const AcceptedEventMessage& object) {
  return object.print(stream);
}

} // namespace OUCH
