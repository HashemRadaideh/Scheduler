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

private:
};
} // namespace OS
