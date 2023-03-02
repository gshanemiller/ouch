#include <ouch_summarize.h>

#include <ouch_header.h>
#include <ouch_system_message.h>
#include <ouch_accepted_message.h>
#include <ouch_canceled_message.h>
#include <ouch_replaced_message.h>

int OUCH::Summarize::parse() {
  assert(d_buffer);

  OUCH::Header *header = reinterpret_cast<OUCH::Header*>(d_buffer);
  header->print(std::cout);

  return 0;
}
