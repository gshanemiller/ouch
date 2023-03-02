#include <ouch_canceled_message.h>

std::ostream& OUCH::CanceledEventMessage::print(std::ostream& stream) const {
  stream << "OUCH::CanceledEventMessage [" << std::endl;

  stream << "  messageLength       : "    << d_messageLength          << std::endl;
  stream << "  packeType           : '"   << d_packeType << "'"       << std::endl;
  stream << "  messageType         : '"   << d_messageType << "'"     << std::endl;
  stream << "  timestamp           : "    << d_timestamp              << std::endl;
  stream << "  orderToken          : '"   << d_orderToken << "'"      << std::endl;
  stream << "  decrementShares     : "    << d_decrementShares        << std::endl;
  stream << "  side                : '"   << d_side << "'"            << std::endl;
  stream << "  reason              : '"   << d_reason << "'"          << std::endl;

  stream << "]" << std::endl;

  return stream;
}
