#pragma once

// Purpose: VST (value semantic type) modeling OUCH 'Header'
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
struct Header {
  // DATA
  u_int16_t   d_streamIdentifier;
  u_int32_t   d_packetLength;

  // CREATORS
  Header();
    // Construct Header object with all members set 0

  Header(const Header& other) = default;
    // Create a Header object holding a copy of specified 'other'. Note that
    // assignment to self is not detected, because copying two fields to self
    // is fast, and idempotent.

  ~Header() = default;
    // Destroy this object

  // MANIPULATORS
  Header& operator=(const Header& rhs) = default;
    // Create and return Header object which is a copy of specified 'rhs'  
    // Note that assignment to self is not detected, because copying two fields
    // to self is fast, and idempotent.

  // ASPECTS
  std::ostream& print(std::ostream& stream) const;
    // Pretty print this object into specified 'stream' returning 'stream'
};
#pragma pack(pop)

// FREE OPERATORS
std::ostream& operator<<(std::ostream& stream, const Header& object);
  // Pretty print specfied 'object' in specified 'stream' returning 'stream'

// INLINE DEFINITIONS
// CREATORS
inline
Header::Header()
: d_streamIdentifier(0)
, d_packetLength(0)
{
}

// INLINE DEFINITIONS
// FREE OPERATORS
inline
std::ostream& operator<<(std::ostream& stream, const Header& object) {
  return object.print(stream);
}

} // namespace OUCH
