#ifndef __CURRENCY_H__
#define __CURRENCY_H__ 

#include <ostream>
#include <string>

class Currency
{

    public:
        Currency() : Currency(0) {}
        Currency(double value) : 
            Currency(value, "Egyptian Pound", "EGP") {}
        Currency(double value, std::string name, std::string isocode) : 
            _value(value), _name(name), _isocode(isocode) {}

        double value() { return _value; }
        std::string name() { return _name; }
        std::string iso_code() { return _isocode; }

        bool compatible(Currency other);
        
        friend bool operator==(Currency c1, Currency c2);
        friend Currency operator+(Currency c1, const Currency &c2);
        friend Currency operator-(Currency c1, const Currency &c2);
        friend Currency operator*(Currency c, double d);
        friend Currency operator/(Currency c, double d);

        //friend Currency operator+=(Currency, Currency);
        Currency& operator+=(const Currency&);
        Currency& operator-=(const Currency&);
        Currency& operator*=(const double);
        Currency& operator/=(const double);

        friend std::ostream& operator<<(std::ostream&, Currency&);

        // Exchange rate implementation
        //friend Currency operator*(Currency c1, Currency c2);
        //friend Currency operator/(Currency c1, Currency c2);

        std::string to_string(std::string prefix = "");

    private:
        std::string _name;
        std::string _isocode;
        double _value;

};

#endif /* ifndef __CURRENCY_H__ */  
