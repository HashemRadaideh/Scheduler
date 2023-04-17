#pragma once

#include <string>

namespace Reader {
typedef long double d96;

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
  Token(Type, std::string, d96, d96);
  Token(Token &&) = default;
  Token(const Token &) = default;
  Token &operator=(Token &&) = default;
  Token &operator=(const Token &) = default;
  ~Token();

  friend std::ostream &operator<<(std::ostream &, const Token &);
  static std::string getTypeof(Type);
  Type getType() const;
  void setType(Type);
  std::string getContent() const;
  void setContent(std::string);
  d96 getStart() const;
  void setStart(d96);
  d96 getEnd() const;
  void setEnd(d96);

private:
  Type type;
  std::string content;
  d96 start;
  d96 end;
};
} // namespace Reader
