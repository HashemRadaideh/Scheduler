#include "OS/Process.hpp"

namespace OS {
Process::Process(std::string name, u64 arrival_time, u64 processing_time) {
  this->name = name;
  this->arrival_time = arrival_time;
  this->processing_time = processing_time;
}

std::string Process::getName() { return this->name; }

u64 Process::getArrivalTime() { return this->arrival_time; }

u64 Process::getProcessingTime() { return this->processing_time; }

Process::~Process() {}
} // namespace OS
