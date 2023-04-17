#pragma once

#include <string>

namespace Reader {
typedef long double ld;

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
  Token(Type, std::string, ld, ld);
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
  ld getStart() const;
  void setStart(ld);
  ld getEnd() const;
  void setEnd(ld);

private:
  Type type;
  std::string content;
  ld start;
  ld end;
};
} // namespace Reader
