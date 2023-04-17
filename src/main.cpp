#include <iostream>

#include "OS/Scheduler.hpp"
#include "Reader/Reader.hpp"

/**
 *-----------------------------------------------------------
 * Title      :  Scheduler
 * Written by :  Hashem Jamel Ahmad Al-Radaideh
 * Student ID :  144609
 * Date       :  Monday, 17th April 2023
 * Site       :  https://github.com/HashemRadaideh/Scheduler
 * Description:
 * Write a scheduler to run and schedule processes in C++.
 *-----------------------------------------------------------
 */

auto main(int argc, char *argv[]) -> int {
  if (argc < 2) {
    std::cerr << "usage: scheduler <input_file>" << std::endl;
    return 1;
  }

  Reader::Reader reader = Reader::Reader(argv[1]);

  OS::Scheduler scheduler =
      OS::Scheduler(reader.getNumberOfProcesses(), reader.getProcesses());

  scheduler.schedule();

  return 0;
}
