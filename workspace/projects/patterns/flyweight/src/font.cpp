#include "font.hpp"
#include <format>
#include <iostream>
#include <memory>
#include <ostream>
#include <regex>
#include <string>

Font::Color::Color(Font::Color::Value value) : _value(value) {}

std::string Font::Color::to_code() const { return _values.at(_value).second; }
std::string Font::Color::to_string() const { return _values.at(_value).first; }
bool Font::Color::operator==(Color& that) 
{
    return (typeid(that) == typeid(Font::Color) && 
            _name == that._name && 
            _code == that._code && 
            _value == that._value);
}



Font::Font(std::string name, int size, Color color) : _name(name), _size(size), _color(color) {}
Font::Font(std::string name, int size) : Font(name, size, Color(Color::Value::RESET)) {}

Font::Ptr Font::create(std::string name, int size) { return std::make_shared<Font>(name, size); }
Font::Ptr Font::create(std::string name, int size, Font::Color color) { return std::make_shared<Font>(name, size, color); }

std::string Font::name() { return _name; }
int Font::size() { return _size; }
Font::Color Font::getColor() { return _color; }

Font::Color Font::reset() { return Color::Value::RESET; }

std::string Font::fullname() { return createFullname(_name, _size, _color); }

std::string Font::format(std::string input) 
{
    return std::format("{}{}{}", getColor().to_code(), input, reset().to_code());
}

std::string Font::format(char ch)
{
    return std::format("{}{}{}", getColor().to_code(), ch, reset().to_code());
}

std::string Font::createFullname(std::string name, int size, Color color)
{
    std::string tname = std::regex_replace(name, std::regex("\\s"), "-");
    return std::format("{}-{}-{}", tname, size, color.to_string());
}

std::string Font::to_string(std::string prefix, std::string flag)
{
    if (flag == "name")
        return fullname();
    return std::format("[Font: name: {} size: {}, color: {}]", _name, _size, _color.to_string());
}

bool Font::operator==(Font& that)
{
    return (typeid(that) == typeid(Font) &&
            name() == that.name() && 
            size() == that.size() &&
            getColor() == that.getColor());
}

bool Font::operator==(Font::Ptr that) { return operator==(*that); }

std::ostream& operator<<(std::ostream& out, Font& font) 
{
    out << font.to_string();
    return out;
}

std::ostream& operator<<(std::ostream& out, Font::Ptr font) 
{
    out << font->to_string();
    return out;
}
