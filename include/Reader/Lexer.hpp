#pragma once
#include "./Token.hpp"
#include <string>

typedef unsigned long long u64;

namespace Reader {
class Lexer {
public:
  Lexer(std::string &);
  Lexer(Lexer &&) = default;
  Lexer(const Lexer &) = default;
  Lexer &operator=(Lexer &&) = default;
  Lexer &operator=(const Lexer &) = default;
  ~Lexer();
  Token lex();
  void next();

protected:
  char peek(int);
  bool isNumber(char);
  bool isAlpha(char);

private:
  std::string text;
  char current;
  u64 position;
};
} // namespace Reader
