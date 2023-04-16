#pragma once

namespace OS {
class Process {
public:
  Process();
  Process(Process &&) = default;
  Process(const Process &) = default;
  Process &operator=(Process &&) = default;
  Process &operator=(const Process &) = default;
  ~Process();

private:
};
} // namespace OS
