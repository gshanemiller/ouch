#include <ouch_system_message.h>

std::ostream& OUCH::SystemEventMessage::print(std::ostream& stream) const {
  stream << "OUCH::SystemEventMessage [" << std::endl;

  stream << "  messageLength       : "    << d_messageLength          << std::endl;
  stream << "  packeType           : '"   << d_packeType << "'"       << std::endl;
  stream << "  messageType         : '"   << d_messageType << "'"     << std::endl;
  stream << "  timestamp           : "    << d_timestamp              << std::endl;
  stream << "  enumeration         : '"   << d_enumeration << "'"     << std::endl;
  
  stream << "]" << std::endl;

  return stream;
}
