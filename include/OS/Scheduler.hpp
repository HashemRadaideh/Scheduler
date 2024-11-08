#pragma once

#include "./Process.hpp"

#include <cstddef>
#include <vector>

namespace OS {
class Scheduler {
public:
  Scheduler(std::size_t, std::vector<OS::Process>);
  Scheduler(Scheduler &&) = default;
  Scheduler(const Scheduler &) = default;
  Scheduler &operator=(Scheduler &&) = default;
  Scheduler &operator=(const Scheduler &) = default;
  ~Scheduler();

  void schedule();
  void longestJobFirst();
  void longestRemainingJobFirst();
  bool match(Process process);

private:
  d96 number_of_processes;
  std::vector<OS::Process> processes;
  std::vector<Process> completed_processes;
  std::vector<Process> ready_queue;
  int total_waiting_time;
  int total_turnaround_time;
};
} // namespace OS
