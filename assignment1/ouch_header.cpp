#include <ouch_header.h>

std::ostream& OUCH::Header::print(std::ostream& stream) const {
  stream << "OUCH::Header [" << std::endl;

  stream << "  streamIndentifier   : "    << d_streamIdentifier       << std::endl;
  stream << "  packetLength        : "    << d_packetLength           << std::endl;

  stream << "]" << std::endl;

  return stream;
}
