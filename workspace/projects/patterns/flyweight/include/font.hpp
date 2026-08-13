#ifndef __FONT_H__
#define __FONT_H__ 

#include <memory>
#include <ostream>
#include <string>
#include <unordered_map>
#include <utility>
class Font
{
    public:
        class Color 
        {
            public:
                enum class Value { RESET, RED, GREEN,YELLOW, BLUE, PURPLE, CYAN };

                Color(Value c);

                std::string to_code() const;
                std::string to_string() const;

                operator Value() const { return _value; }

                bool operator==(Color&);

            private:
                const std::pmr::unordered_map<Value, std::pair<std::string, std::string>> _values = 
                {
                    { Value::RESET,     { "RESET",  "\033[0m" } },
                    { Value::RED,       { "RED",    "\033[0;31m" } },
                    { Value::GREEN,     { "GREEN",  "\033[0;32m" } },
                    { Value::YELLOW,    { "YELLOW", "\033[0;33m" } },
                    { Value::BLUE,      { "BLUE",   "\033[0;34m" } },
                    { Value::PURPLE,    { "PURPLE", "\033[0;35m" } },
                    { Value::CYAN,      { "CYAN",   "\033[0;36m" } }
                };
                std::string     _name;
                std::string     _code;
                Value           _value;
        };

        using Ptr = std::shared_ptr<Font>;

        static Ptr create(std::string name, int size);
        static Ptr create(std::string name, int size, Color color);

    private:
        std::string _name;
        std::string _fullname;
        int _size;
        Color _color;

    public:
        Font(std::string name, int size);
        Font(std::string name, int size, Color color);

        std::string name();
        int size();
        Color getColor();
        Color reset();
        std::string fullname();
        std::string format(std::string);
        std::string format(char);

        static std::string createFullname(std::string name, int size, Color color);

        std::string to_string(std::string prefix="", std::string flag = "name");

        bool operator==(Font&);
        bool operator==(Font::Ptr);

        friend std::ostream& operator<<(std::ostream&, Font&);
        friend std::ostream& operator<<(std::ostream&, Font::Ptr);

};

#endif /* ifndef __FONT_H__ */
