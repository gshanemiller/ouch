#pragma once

// Purpose: VST (value semantic type) modeling OUCH 'ReplacedEventMessage'
//
// Exception Policy:
//    Exception free
//
// MT Safety:
//    const MT safe only
// 

#include <ouch_text_sizes.h>
#include <iostream>
#include <sys/types.h>

namespace OUCH {

#pragma pack(push,1)
struct ReplacedEventMessage {
  // DATA
  u_int16_t   d_messageLength;
  int8_t      d_packeType;
  int8_t      d_messageType;
  u_int64_t   d_timestamp;
  int8_t      d_orderToken[TextSize::kMAX_ORDER_TOKEN_SIZE];
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
  int8_t      d_previousOrderToken[TextSize::kMAX_PREVIOUS_ORDER_TOKEN_SIZE];

  // CREATORS
  ReplacedEventMessage();
    // Construct Header object with all members set 0

  ReplacedEventMessage(const ReplacedEventMessage& other);
    // Create a ReplacedEventMessage object holding a copy of specified 'other'.

  ~ReplacedEventMessage() = default;
    // Destroy this object

  // MANIPULATORS
  ReplacedEventMessage& operator=(const ReplacedEventMessage& rhs);
    // Create and return ReplacedEventMessage object which is a copy of
    // specified 'rhs'  

  // ASPECTS
  std::ostream& print(std::ostream& stream) const;
    // Pretty print this object into specified 'stream' returning 'stream'
};
#pragma pack(pop)

// FREE OPERATORS
std::ostream& operator<<(std::ostream& stream, const ReplacedEventMessage& object);
  // Pretty print specfied 'object' in specified 'stream' returning 'stream'


// INLINE DEFINITIONS
// CREATORS
inline
ReplacedEventMessage::ReplacedEventMessage() {
  memset(this, 0, sizeof(ReplacedEventMessage));
}

inline
ReplacedEventMessage::ReplacedEventMessage(const ReplacedEventMessage& other) {
  if (&other != this) {
    memcpy(this, &other, sizeof(ReplacedEventMessage));
  }
}

// INLINE DEFINITIONS
// MANIPULATORS
inline
ReplacedEventMessage& ReplacedEventMessage::operator=(const ReplacedEventMessage& rhs) {
  if (&rhs != this) {
    memcpy(this, &rhs, sizeof(ReplacedEventMessage));
  }
  return *this;
}

// INLINE DEFINITIONS
// FREE OPERATORS
inline
std::ostream& operator<<(std::ostream& stream, const ReplacedEventMessage& object) {
  return object.print(stream);
}

} // namespace OUCH
