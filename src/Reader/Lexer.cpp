#include "Reader/Lexer.hpp"

namespace Reader {
Lexer::Lexer(std::string &text) {
  this->text = text;
  this->position = 0;
  this->current = this->text[this->position++];
}

Lexer::~Lexer() {}

void Lexer::next() {
  if (this->position >= text.length())
    this->current = '\0';
  else
    this->current = this->text[this->position++];
}

char Lexer::peek(int index = 0) { return this->text[this->position + index]; }

bool Lexer::isNumber(char character) {
  return character >= '0' && character <= '9';
}

bool Lexer::isAlpha(char character) {
  return (character == '_') || (character >= 'A' && character <= 'Z') ||
         (character >= 'a' && character <= 'z');
}

Token Lexer::lex() {
  switch (this->current) {
  case '\0':
    return Token(Type::eof);

  case ' ':
    return Token(Type::skip);

  case '\n':
    return Token(Type::skip);

  case '\t':
    return Token(Type::skip);
  }

  if (isNumber(this->current)) {
    Token token = Token();

    token.setType(Type::number);

    std::string str = {this->current};

    token.setStart(this->position - 1);
    while (isNumber(peek(0))) {
      next();
      str += this->current;
    }
    token.setEnd(this->position - 1);

    token.setContent(str);

    return token;
  } else if (isAlpha(this->current) || this->current == '_') {
    Token token = Token();

    std::string str = {this->current};

    token.setStart(this->position - 1);
    while (isAlpha(peek(0)) || isNumber(peek(0)) || peek(0) == '_') {
      next();
      str += this->current;
    }
    token.setEnd(this->position - 1);

    token.setContent(str);

    return token;
  }

  return Token();
}
} // namespace Reader
