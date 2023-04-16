#include <fstream>
#include <iostream>
#include <string>

#include "OS/Scheduler.hpp"
#include "Reader/Reader.hpp"

auto main(int argc, char *argv[]) -> int {
  if (argc < 2) {
    std::cerr << "usage: scheduler <input_file>" << std::endl;
    return 1;
  }

  std::ifstream file = std::ifstream(argv[1]);

  if (file.fail()) {
    std::cerr << "File not found\n";
    return 1;
  }

  std::string line = "";
  std::string content = "";
  while (std::getline(file, line)) {
    content += line + "\n";
  }

  Reader::Reader generator = Reader::Reader(content);
  OS::Scheduler scheduler = OS::Scheduler();

  return 0;
}
