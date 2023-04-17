#pragma once

#include <string>

typedef unsigned long long u64;

namespace OS {
class Process {
public:
  Process(std::string, u64, u64);
  Process(Process &&) = default;
  Process(const Process &) = default;
  Process &operator=(Process &&) = default;
  Process &operator=(const Process &) = default;
  ~Process();
  std::string getName();
  u64 getArrivalTime();
  u64 getProcessingTime();

private:
  std::string name;
  u64 arrival_time;
  u64 processing_time;
};
} // namespace OS
