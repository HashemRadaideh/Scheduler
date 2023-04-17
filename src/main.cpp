#include <iostream>

#include "OS/Scheduler.hpp"
#include "Reader/Reader.hpp"

auto main(int argc, char *argv[]) -> int {
  if (argc < 2) {
    std::cerr << "usage: scheduler <input_file>" << std::endl;
    return 1;
  }

  Reader::Reader reader = Reader::Reader(argv[1]);

  std::cout << reader.getNumberOfProcesses() << std::endl;

  for (auto x : reader.getProcesses()) {
    std::cout << x.getName() << " " << x.getArrivalTime() << " "
              << x.getProcessingTime() << std::endl;
  }

  OS::Scheduler scheduler =
      OS::Scheduler(reader.getNumberOfProcesses(), reader.getProcesses());

  return 0;
}
