#include "OS/Scheduler.hpp"

#include <algorithm>
#include <iostream>

#ifdef _WIN32
#include <windows.h>
#else
#include <unistd.h>
#endif // _WIN32

namespace OS {
Scheduler::Scheduler(std::size_t number_of_processes,
                     std::vector<OS::Process> processes) {
  this->number_of_processes = number_of_processes;
  this->processes = processes;

  total_waiting_time = 0;
  total_turnaround_time = 0;

  this->processes.erase(
      std::remove_if(begin(this->processes), end(this->processes),
                     [](const Process &p) { return !p.isAlive(); }),
      end(this->processes));
}

Scheduler::~Scheduler() {}

bool Scheduler::match(Process process) {
  for (auto x : ready_queue) {
    if (x.getName() == process.getName())
      return true;
  }
  return false;
}

void Scheduler::longestJobFirst() {
  for (int current_time = 0;
       completed_processes.size() != number_of_processes;) {
    for (auto &process : processes) {
      if (process.getArrivalTime() <= current_time && !match(process)) {
        ready_queue.emplace_back(process);
      }
    }

    std::sort(begin(this->ready_queue), end(this->ready_queue),
              [](const Process &p1, const Process &p2) {
                return p1.getRemainingTime() > p2.getRemainingTime();
              });

    if (ready_queue.empty()) {
      current_time = processes.front().getArrivalTime();
      continue;
    }

    Process &current_process = ready_queue.front();

    current_process.setResponseTime(current_time);

    current_time += current_process.getProcessingTime();

    current_process.process(current_time);

    current_process.setCompletionTime(current_time);

    total_waiting_time += current_process.getWaitingTime();
    total_turnaround_time += current_process.getTurnaroundTime();

    completed_processes.emplace_back(current_process);

    processes.erase(std::remove_if(begin(processes), end(processes),
                                   [&](const Process &p) {
                                     return p.getName() ==
                                            current_process.getName();
                                   }),
                    end(processes));

    ready_queue.erase(ready_queue.begin());
  }
}

void Scheduler::schedule() {
  if (processes.empty()) {
    return;
  }

  std::cout << this->number_of_processes << std::endl;

  for (auto &process : this->processes)
    std::cout << process.getName() << " " << process.getArrivalTime() << " "
              << process.getProcessingTime() << std::endl;

  longestJobFirst();

  for (auto &process : completed_processes) {
    std::cout << process.getName()
              << ": (response = " << process.getResponseTime()
              << ", turnaround = " << process.getTurnaroundTime()
              << ", delay = " << process.getWaitingTime() << ")" << std::endl;
  }

  for (auto &process : completed_processes) {
    std::cout << process.getName();
  }

  std::cout << "\nAverage waiting time: "
            << (double)total_waiting_time / number_of_processes << std::endl;
  std::cout << "Average turnaround time: "
            << (double)total_turnaround_time / number_of_processes << std::endl;
}
} // namespace OS
