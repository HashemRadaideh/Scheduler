#include "Reader/AST.hpp"

namespace Reader {
Expression::Expression() {
  this->type = Type::undefined;
  this->token = Token();
}
Expression::Expression(Type type, Token token) {
  this->type = type;
  this->token = token;
}

Expression::~Expression() {}

Number::Number(Token) {}

Number::Number() {}

Number::~Number() {}

Name::Name(Token) {}

Name::Name() {}

Name::~Name() {}

Process::Process(Name *name, Number *arrival_time, Number *processing_time) {
  this->name = name;
  this->arrival_time = arrival_time;
  this->processing_time = processing_time;
}

Process::~Process() {}
} // namespace Reader
