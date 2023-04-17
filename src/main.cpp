#include <iostream>

#include "OS/Scheduler.hpp"
#include "Reader/Reader.hpp"

auto main(int argc, char *argv[]) -> int {
  if (argc < 2) {
    std::cerr << "usage: scheduler <input_file>" << std::endl;
    return 1;
  }

  Reader::Reader reader = Reader::Reader(argv[1]);

  OS::Scheduler scheduler =
      OS::Scheduler(reader.getNumberOfProcesses(), reader.getProcesses());

  scheduler.schedule();

  return 0;
}
