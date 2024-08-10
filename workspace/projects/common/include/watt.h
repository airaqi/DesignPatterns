#ifndef __WATT_H__
#define __WATT_H__ 

#include <string>

class Watt 
{
    public:
        Watt() : Watt(0) {}
        Watt(int value) : _value(value) {}
        int value() { return _value; }

        friend bool operator==(Watt w1, Watt w2);
        friend Watt operator+(Watt w1, Watt w2);
        friend Watt operator-(Watt w1, Watt w2);
        friend Watt operator*(Watt w, double d);
        friend Watt operator/(Watt w, double d);

        std::string to_string();

    private:
        int _value;
};

#endif /* ifndef __WATT_H__ */
