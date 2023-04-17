#pragma once

#include "./Token.hpp"

typedef unsigned long long u64;

namespace Reader {
class Expression {
public:
  Expression();
  Expression(Type, Token);
  Expression(Expression &&) = default;
  Expression(const Expression &) = default;
  Expression &operator=(Expression &&) = default;
  Expression &operator=(const Expression &) = default;
  ~Expression();
  Type getType();
  void setType(Type);
  Token getToken();
  void setToken(Token);
  std::string getContent();

private:
  Type type;
  Token token;
};

class Name : public Expression {
public:
  Name();
  Name(Token);
  Name(Name &&) = default;
  Name(const Name &) = default;
  Name &operator=(Name &&) = default;
  Name &operator=(const Name &) = default;
  ~Name();

private:
};

class Number : public Expression {
public:
  Number();
  Number(Token);
  Number(Number &&) = default;
  Number(const Number &) = default;
  Number &operator=(Number &&) = default;
  Number &operator=(const Number &) = default;
  ~Number();

private:
};

class Process : public Expression {
public:
  Process(Name *, Number *, Number *);
  Process(Process &&) = default;
  Process(const Process &) = default;
  Process &operator=(Process &&) = default;
  Process &operator=(const Process &) = default;
  ~Process();
  std::string getName();
  u64 getArrivalTime();
  u64 getProcessingTime();

private:
  Name *name;
  Number *arrival_time;
  Number *processing_time;
};
} // namespace Reader
