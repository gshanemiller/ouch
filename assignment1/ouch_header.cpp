#include <ouch_header.h>

std::ostream& OUCH::Header::print(std::ostream& stream) const {
  stream << "OUCH::Header [" << std::endl;

  stream << "  streamIndentifier   : "    << __builtin_bswap16(d_streamIdentifier)      << std::endl;
  stream << "  packetLength        : "    << __builtin_bswap32(d_packetLength)          << std::endl;

  stream << "]" << std::endl;

  return stream;
}
