#pragma once

#include "./AST.hpp"
#include "./Lexer.hpp"

#include <string>

namespace Reader {
class Parser {
public:
  Parser();
  Parser(std::string &);
  Parser(Parser &&) = default;
  Parser(const Parser &) = default;
  Parser &operator=(Parser &&) = default;
  Parser &operator=(const Parser &) = default;
  ~Parser();

  Token next();
  Expression *parse();
  Expression *parseCurrent();

private:
  Lexer lexer;
  Expression *root;
  Token current;
};
} // namespace Reader
