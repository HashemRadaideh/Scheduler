#pragma once

#include <string>

namespace OS {
typedef long double d96;

class Process {
public:
  Process(std::string, d96, d96);
  Process(Process &&) = default;
  Process(const Process &) = default;
  Process &operator=(Process &&) = default;
  Process &operator=(const Process &) = default;
  ~Process();

  std::string getName() const;
  d96 getArrivalTime() const;
  d96 getProcessingTime() const;
  d96 getRemainingTime() const;
  d96 getTurnaroundTime() const;
  d96 getWaitingTime() const;
  d96 getResponseTime() const;
  bool isAlive() const;
  bool isCompleted() const;
  bool hasStarted();
  void setCompletionTime(d96);
  void setResponseTime(d96);
  void process(d96);

private:
  std::string name;
  d96 arrival_time;
  d96 processing_time;
  d96 remaining_time;
  d96 response_time;
  d96 completion_time;
  d96 turnaround_time;
  d96 waiting_time;
  bool started;
};
} // namespace OS
