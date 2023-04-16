#pragma once

#include "Reader/AST.hpp"

namespace OS {
class Process {
public:
  Process(Reader::Name *, Reader::Number *, Reader::Number *);
  Process(Process &&) = default;
  Process(const Process &) = default;
  Process &operator=(Process &&) = default;
  Process &operator=(const Process &) = default;
  ~Process();

private:
};
} // namespace OS
