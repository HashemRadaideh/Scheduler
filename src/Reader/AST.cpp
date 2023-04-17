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

void Expression::setType(Type type) { this->type = type; }

Type Expression::getType() const { return this->type; }

Token Expression::getToken() const { return this->token; }

void Expression::setToken(Token token) { this->token = token; }

std::string Expression::getContent() const { return this->token.getContent(); }

Number::Number(Token number) {
  this->setType(Type::number);
  this->setToken(number);
}

Number::Number() { this->setType(Type::number); }

Number::~Number() {}

Name::Name(Token string) {
  this->setType(Type::name);
  this->setToken(string);
}

Name::Name() { this->setType(Type::name); }

Name::~Name() {}

Process::Process(Name *name, Number *arrival_time, Number *processing_time) {
  this->name = name;
  this->arrival_time = arrival_time;
  this->processing_time = processing_time;
}

Process::~Process() {}

std::string Process::getName() const { return this->name->getContent(); }

ld Process::getArrivalTime() const {
  return std::stoi(this->arrival_time->getContent());
}

ld Process::getProcessingTime() const {
  return std::stoi(this->processing_time->getContent());
}
} // namespace Reader
