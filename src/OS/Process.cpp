#include "OS/Process.hpp"

namespace OS {
Process::Process(std::string name, ld arrival_time, ld processing_time) {
  this->name = name;
  this->arrival_time = arrival_time;
  this->processing_time = processing_time;
  this->started = false;
  this->remaining_time = processing_time;
  this->response_time = 0;
  this->completion_time = 0;
  this->turnaround_time = 0;
  this->waiting_time = 0;
}

Process::~Process() {}

std::string Process::getName() const { return this->name; }

ld Process::getArrivalTime() const { return this->arrival_time; }

ld Process::getProcessingTime() const { return this->processing_time; }

bool Process::isAlive() const { return this->remaining_time != 0; }

bool Process::hasStarted() { return this->started; }

void Process::setResponseTime(ld response_time) {
  this->response_time = response_time - this->arrival_time;
  this->started = true;
  ;
}

ld Process::getResponseTime() const { return this->response_time; }

void Process::process(ld time_unit) {
  if (remaining_time >= time_unit) {
    remaining_time -= time_unit;
  } else {
    remaining_time = 0;
  }
}

ld Process::getRemainingTime() const { return this->remaining_time; }

bool Process::isCompleted() const { return remaining_time == 0; }

void Process::setCompletionTime(ld completion_time) {
  this->completion_time = completion_time;
  this->turnaround_time = completion_time - arrival_time;
  this->waiting_time = getTurnaroundTime() - processing_time;
}

ld Process::getTurnaroundTime() const { return turnaround_time; }

ld Process::getWaitingTime() const { return waiting_time; }
} // namespace OS
