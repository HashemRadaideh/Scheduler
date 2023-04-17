#include "Reader/Reader.hpp"
#include "OS/Process.hpp"

#include <cstdlib>
#include <fstream>
#include <iostream>
#include <string>

namespace Reader {
Reader::Reader(const char *file_name) {
  std::ifstream file = std::ifstream(file_name);

  if (file.fail()) {
    std::cerr << "File not found\n";
    std::exit(1);
  }

  std::string line = "";
  std::string content = "";
  while (std::getline(file, line)) {
    content += line + "\n";
  }

  this->parser = Parser(content);

  this->root = parser.parse();
  this->number_of_processes = std::stoi(this->root->getContent());

  this->root = parser.parse();
  while (this->root->getType() != Type::eof) {
    Process *process = (Process *)root;
    this->processes.emplace_back(OS::Process(process->getName(),
                                             process->getArrivalTime(),
                                             process->getProcessingTime()));
    this->root = parser.parse();
  }
}

Reader::~Reader() {}

std::vector<OS::Process> Reader::getProcesses() const {
  return this->processes;
}

std::size_t Reader::getNumberOfProcesses() const {
  return this->number_of_processes;
}
} // namespace Reader
