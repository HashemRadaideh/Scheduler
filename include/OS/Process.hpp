#pragma once

#include <string>

namespace OS {
typedef long double ld;

class Process {
public:
  Process(std::string, ld, ld);
  Process(Process &&) = default;
  Process(const Process &) = default;
  Process &operator=(Process &&) = default;
  Process &operator=(const Process &) = default;
  ~Process();

  std::string getName() const;
  ld getArrivalTime() const;
  ld getProcessingTime() const;
  ld getRemainingTime() const;
  ld getTurnaroundTime() const;
  ld getWaitingTime() const;
  ld getResponseTime() const;
  bool isAlive() const;
  bool isCompleted() const;
  bool hasStarted();
  void setCompletionTime(ld);
  void setResponseTime(ld);
  void process(ld);

private:
  std::string name;
  ld arrival_time;
  ld processing_time;
  ld remaining_time;
  ld response_time;
  ld completion_time;
  ld turnaround_time;
  ld waiting_time;
  bool started;
};
} // namespace OS
