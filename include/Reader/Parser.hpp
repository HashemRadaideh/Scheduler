#pragma once

namespace Reader {
class Parser {
public:
  Parser();
  Parser(Parser &&) = default;
  Parser(const Parser &) = default;
  Parser &operator=(Parser &&) = default;
  Parser &operator=(const Parser &) = default;
  ~Parser();

private:
};
} // namespace Reader
