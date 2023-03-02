cmake_minimum_required(VERSION 3.16)

# ------------

set(SOURCES                                                                                                             
  ouch_text_sizes.cpp
  ouch_accepted_message.cpp
  ouch_canceled_message.cpp
  ouch_header.cpp
  ouch_replaced_message.cpp
  ouch_system_message.cpp
  ouch_summarize.cpp
  main.cpp
) 

set(TARGET summarize.tsk)
add_executable(${TARGET} ${SOURCES})
target_compile_options(${TARGET} PUBLIC -g -O1)
target_include_directories(${TARGET} PUBLIC .)
# target_compile_definitions(${TARGET} PUBLIC NDEBUG)
