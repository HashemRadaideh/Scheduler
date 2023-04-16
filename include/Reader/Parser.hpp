#pragma once

#include "./AST.hpp"
#include "./Lexer.hpp"
#include <string>

namespace Reader {
class Parser {
public:
  Parser(std::string &, bool);
  Parser(Parser &&) = default;
  Parser(const Parser &) = default;
  Parser &operator=(Parser &&) = default;
  Parser &operator=(const Parser &) = default;
  ~Parser();

  Expression *getExpression();
  Token next();
  Expression *parse();
  Expression *parseProcess();
  Expression *parseCurrent();

private:
  bool printTokens;
  Lexer lexer;
  Expression *root;
  Token current;
};
} // namespace Reader
