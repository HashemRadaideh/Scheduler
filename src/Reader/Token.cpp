#include "Reader/Token.hpp"

#include <iostream>

namespace Reader {
Token::Token(Type type, std::string value, ld start, ld end) {
  this->type = type;
  this->content = value;
  this->start = start;
  this->end = (start > end) ? start : end;
}

Token::Token(Type type) {
  this->type = type;
  this->content = "";
  this->start = 0;
  this->end = 0;
}

Token::Token() {
  this->type = Type::undefined;
  this->content = "";
  this->start = 0;
  this->end = 0;
}

Token::~Token() {}

std::ostream &operator<<(std::ostream &os, const Token &token) {
  return os << "Token: " << Token::getTypeof(token.type) << std::endl
            << "Value: " << token.content << std::endl
            << "At: " << token.start << " - " << token.end;
}

Type Token::getType() const { return this->type; }

void Token::setType(Type type) { this->type = type; }

std::string Token::getContent() const { return this->content; }

void Token::setContent(std::string value) { this->content = value; }

ld Token::getStart() const { return this->start; }

void Token::setStart(ld position) { this->start = position; }

ld Token::getEnd() const { return this->end; }

void Token::setEnd(ld position) { this->end = position; }

std::string Token::getTypeof(Type currentType) {
  if (currentType == Type::name)
    return "name literal";
  if (currentType == Type::number)
    return "number literal";
  else if (currentType == Type::eof)
    return "EOF";
  return "Unkown token type";
}
} // namespace Reader
