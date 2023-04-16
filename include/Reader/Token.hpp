#pragma once

#include <string>

namespace Reader {
enum class Type {
  name = 0,
  number = 1,
  undefined = -1,
  skip = -2,
  eof = -3,
};

class Token {
public:
  Token();
  Token(Type);
  Token(Type, std::string, int, int);
  Token(Token &&) = default;
  Token(const Token &) = default;
  Token &operator=(Token &&) = default;
  Token &operator=(const Token &) = default;
  ~Token();
  friend std::ostream &operator<<(std::ostream &, const Token &);
  static std::string getTypeof(Type);
  Type getType();
  void setType(Type);
  std::string getContent();
  void setContent(std::string);
  int getStart();
  void setStart(int);
  int getEnd();
  void setEnd(int);

private:
  Type type;
  std::string content;
  int start;
  int end;
};
} // namespace Reader
