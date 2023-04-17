#include "Reader/Parser.hpp"
#include "Reader/AST.hpp"

#include <iostream>

namespace Reader {
Parser::Parser() : lexer() {
  this->current = next();
  this->root = nullptr;
}

Parser::Parser(std::string &line) : lexer(line) {
  this->current = next();
  this->root = nullptr;
}

Parser::~Parser() { delete this->root; }

Token Parser::next() {
  Token token = lexer.lex();

  // if (token.getType() != Type::skip && token.getType() != Type::eof)
  //   std::cout << token << std::endl;

  if (token.getType() == Type::skip)
    token = next();

  this->current = token;

  return token;
}

Expression *Parser::parse() {
  Expression *left = parseCurrent();

  while (this->current.getType() == Type::number) {
    Number *arrival_time = (Number *)parseCurrent();
    Number *processing_time = (Number *)parseCurrent();

    left = new Process((Name *)left, arrival_time, processing_time);
  }

  return left;
}

Expression *Parser::parseCurrent() {
  if (this->current.getType() == Type::number) {
    Number *node = new Number(this->current);
    next();
    return node;
  }

  if (this->current.getType() == Type::name) {
    Name *node = new Name(this->current);
    next();
    return node;
  }

  if (this->current.getType() == Type::eof) {
    return new Expression(Type::eof, this->current);
  }

  return new Expression();
}
} // namespace Reader
