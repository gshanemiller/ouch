#include <stdio.h>
#include <errno.h>
#include <string.h>
#include <unistd.h>
#include <sys/stat.h>

#include <ouch_summarize.h>

u_int64_t fileSize;
std::string fileName;

void usageAndExit() {
  printf("usage: summarize.tsk -f <filename>\n");
  exit(2);
}

void processCommandLine(int argc, char **argv) {
  int c;

  while ((c = getopt (argc, argv, "f:")) != -1) {
    switch(c) {
      case 'f':
      {
        struct stat fs;
        if (stat(optarg, &fs)!=0) {
          printf("Cannot determine filesize of '%s': %s\n", optarg, strerror(errno));
          exit(1);
        }
        if (fs.st_size> 0x40000000) {
          printf("file '%s' is too large at %lu bytes. Maximum is 1Gb\n", optarg, fs.st_size);
          exit(1);
        }
        fileSize = fs.st_size;
        fileName = optarg;
        break;
      }
      default:
        usageAndExit();
    }
  }

  if (fileName.empty()) {
    usageAndExit();
  }
}

int main(int argc, char **argv) {
  processCommandLine(argc, argv);

  printf("processing '%s' %lu bytes ...\n", fileName.c_str(), fileSize);

  OUCH::Summarize summary(fileName, fileSize);
  if (0!=summary.process()) {
    printf("summary failed\n");
    return 1;
  }

  return 0;
}
