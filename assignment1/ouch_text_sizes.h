#pragma once

// Purpose: Provide VST (value semantic classes) modeling one OUCH type each
//
// Exception Policy:
//    Exception free
//
// MT Safety:
//    const MT safe only
// 

namespace OUCH {

enum TextSize {
  kMAX_TEXT_SIZE = 14,
  kMAX_SYMBOL_SIZE = 8,
  kMAX_FIRM_SIZE = 4,
  kMAX_ORDER_TOKEN_SIZE = 14,
  kMAX_PREVIOUS_ORDER_TOKEN_SIZE = 14
};

} // namespace OUCH
