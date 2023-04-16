#pragma once

namespace OS {
class Scheduler {
public:
  Scheduler();
  Scheduler(Scheduler &&) = default;
  Scheduler(const Scheduler &) = default;
  Scheduler &operator=(Scheduler &&) = default;
  Scheduler &operator=(const Scheduler &) = default;
  ~Scheduler();

private:
};
} // namespace OS
