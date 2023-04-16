#pragma once

#include <string>

namespace Reader {
class Reader {
public:
  Reader(std::string &);
  Reader(Reader &&) = default;
  Reader(const Reader &) = default;
  Reader &operator=(Reader &&) = default;
  Reader &operator=(const Reader &) = default;
  ~Reader();

private:
};
} // namespace Reader
