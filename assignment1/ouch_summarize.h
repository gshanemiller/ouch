#pragma once

// Purpose: Read file containing valid OUCH messages and summarize data
//
// Classes:
//    Summarize: opens, and reads named file and summarizes message content
//
// Exception Policy:
//    Exception free
//
// MT Safety:
//    const MT safe only
// 

#include <ouch_text_sizes.h>
#include <iostream>
#include <assert.h>
#include <sys/types.h>
#include <fcntl.h>
#include <unistd.h>

namespace OUCH {

class Summarize {
  // DATA
  std::string d_fileName;
  u_int64_t   d_fileSize;
  u_int8_t   *d_buffer;
  u_int32_t   d_rc;

public:
  // CREATORS
  Summarize(const std::string& fileName, u_int64_t fileSize);
    // Construct Summarize object on specified 'fileName' containing 'fileSize'
    // bytes. Behavior is defined provided '!fileName.empty()', 'fileName' exists
    // and '0<fileSize<=1073741824'.

  Summarize() = delete;
    // Default constructor not provided

  Summarize(const Summarize& other) = delete;
    // Copy constructor not provided

  ~Summarize();
    // Destroy this object

  // MANIPULATORS
  int process();
    // Return 0 if the file provided at construction time was read, and summarized
    // and non-zero otherwise. Note that calling 'process()' is idempotent; the
    // second and subsequent calls do nothing. Upon return callers can invoke
    // 'print()' to give a human readable synopsis in a provided stream.

  Summarize& operator=(const Summarize& rhs) = default;
    // Assignment operator not provided

  // ASPECTS
  std::ostream& print(std::ostream& stream) const;
    // Pretty print this object into specified 'stream' returning 'stream'

private:
  // PRIVATE MANIPULATORS
  int readFile();
    // Return 0 if 'd_fileName' was opened and the first 'd_fileSize' bytes
    // were read into 'd_buffer', which is allocated first, and non-zero
    // othewise. Behavior is defined provided 'd_buffer==0' on entry.

  int parse();
};

// FREE OPERATORS
std::ostream& operator<<(std::ostream& stream, const Summarize& object);
  // Pretty print specfied 'object' in specified 'stream' returning 'stream'

// INLINE DEFINITIONS
// CREATORS
inline
Summarize::Summarize(const std::string& fileName, u_int64_t fileSize)
: d_fileName(fileName)
, d_fileSize(fileSize)
, d_buffer(0)
, d_rc(0)
{
  assert(!d_fileName.empty());
  assert(d_fileSize>0);
  assert(d_fileSize<=0x40000000);
}

inline
int Summarize::process() {
  // If already process file, return last rc code
  if (d_buffer) {
    return d_rc;
  }

  // Read file into memory
  if (0!=(d_rc = readFile())) {
    return d_rc;
  }

  d_rc = parse();
  return d_rc;
}

inline
Summarize::~Summarize() {
  if (d_buffer) {
    delete [] d_buffer;
  }
  d_buffer = 0;
}

// INLINE DEFINITIONS
// PRIVATE MANIPULATORS
inline
int Summarize::readFile() {
  assert(0==d_buffer);
  d_buffer = new u_int8_t[d_fileSize];
  assert(d_buffer);

  int fid = open(d_fileName.c_str(), O_RDONLY);
  if (fid==-1) {
    assert(errno!=0);
    return errno;
  }

  auto sz = read(fid, d_buffer, d_fileSize);
  close(fid);

  printf("read %lu bytes\n", sz);

  for (unsigned i=0; i<50; ++i) {
    printf("%02x ", d_buffer[i]);
  }
  printf("\n");

  return !(static_cast<u_int64_t>(sz)==d_fileSize);
}

// INLINE DEFINITIONS
// FREE OPERATORS
inline
std::ostream& operator<<(std::ostream& stream, const Summarize& object) {
  return object.print(stream);
}

} // namespace OUCH
