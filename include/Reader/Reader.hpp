#pragma once

#include "OS/Process.hpp"
#include "Reader/Parser.hpp"

#include <cstddef>
#include <string>
#include <vector>

namespace Reader {
class Reader {
public:
  Reader(const char *);
  Reader(Reader &&) = default;
  Reader(const Reader &) = default;
  Reader &operator=(Reader &&) = default;
  Reader &operator=(const Reader &) = default;
  ~Reader();
  void read();
  std::vector<OS::Process> getProcesses();
  std::size_t getNumberOfProcesses();

private:
  Parser parser;
  Expression *root;
  std::size_t number_of_processes;
  std::vector<OS::Process> processes;
};
} // namespace Reader
