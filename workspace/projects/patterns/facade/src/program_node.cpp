#include "program_node.hpp"
#include "compiler_scanner.hpp"
#include <ctime>
#include <format>
#include <iostream>
#include <ostream>
#include <stdexcept>
#include <string>

ProgNode::ProgNode() : _id(ProgNode::next_id()), _scope(nullptr), _line(Scanner::line()), _index(Scanner::index()) {}
ProgNode::~ProgNode() {}

void ProgNode::error(std::string s) 
{
    // get currency time stamp
    std::time_t now = time(0);
    std::tm* timeinfo = localtime(&now);
    char timestamp[20];
    strftime(timestamp, sizeof(timestamp), "%Y-%m-%d %H:%M:%S", timeinfo);
    throw std::runtime_error(std::format("[{}] near ({}, {}) : {}", timestamp, line(), index(), s));
}

void ProgNode::define(std::string s, ProgNode::Ptr p)       {}
void ProgNode::undefine(std::string s)                      {}
bool ProgNode::exists(std::string s)                        { return false; }
ProgNode::Ptr ProgNode::get(std::string s)                  { return nullptr; }

bool ProgNode::isExpression()                               { return false; }
bool ProgNode::isStatement()                                { return false; }
bool ProgNode::isBlock()                                    { return false; }
bool ProgNode::isValue()                                    { return false; }
bool ProgNode::isVariable()                                 { return false; }

// Setters and getters
int ProgNode::id() const                { return _id; }     void ProgNode::id(int i)                { _id = i; }
int ProgNode::line() const              { return _line; }   void ProgNode::line(int l)              { _line = l; }
int ProgNode::index() const             { return _index; }  void ProgNode::index(int i)             { _index = i; }
ProgNode::Ptr ProgNode::scope() const   { return _scope; }  void ProgNode::scope(ProgNode::Ptr s)   { _scope = s; }

int ProgNode::next_id()     { return _next_id++; }

void ProgNode::emitlabel(int i) { std::cout << "L" << i << ":"; }
void ProgNode::emit(std::string s) const { std::cout << "\t" << s << std::endl; }
int ProgNode::newlabel() { return ++_labels; }

bool ProgNode::operator==(const ProgNode& that) const { return equals(that); }
bool ProgNode::operator!=(const ProgNode& that) const { return !equals(that); }

std::ostream& operator<<(std::ostream& out, const ProgNode& that) { out << that.to_string(); return out; }
std::ostream& operator<<(std::ostream& out, const ProgNode::Ptr that) { return operator<<(out, *that.get()); }

