#ifndef __MONEY_H__
#define __MONEY_H__ 

#include <limits>
#include <string>
class Money 
{
    private:
        /* "The mill is unit of currency, used in several countries as one-
         * thousandth of the main unit." (in this case GBP.) This is 
         * at least 64 bits wide, to be able to represent amounts larger then
         * 2,147,483.64. It has one extra digit of precision, to ensure 
         * proper rounding.
         *
         * If a long double has fewer than 63 mantissa bits, this implementation
         * might incorrectly round off extremely large credits or debits. You
         * might want to flag this and throw a std::range_error exception.
         */

        long long mills;

        /* Compile-time constants. I originally had definitions of these in
         * namespace scope as well, nut that is no longer necessary and is now
         * deprecated.
         */
        static constexpr auto money_max = std::numeric_limits<decltype(mills)>::max();
        static constexpr auto money_min = std::numeric_limits<decltype(mills)>::min();
        static constexpr int mills_per_gbp = 1000;
        static constexpr int mills_per_penny = 10;

        /* Used internally to bypass round-trip conversation. The dummy parameter is 
         * there only to distinguish this constructor from the one that takes a
         * value in pounds.
         */
        struct dummy_t   {};

        explicit constexpr Money(long long source, dummy_t) noexcept;

    public:
        // Use the trivial default constructor instead of a custom one.
        Money() noexcept = default;

        /* Allow either Money(12.34) or Money(12,34). Note that Money(12.345)
         * is legal, but Money(12,345) should throw a std::invalid_argument
         * exception.
         */
        constexpr Money(long double amount);
        constexpr Money(long long int main, unsigned sub);
        // The implicit members would have sufficed.
        constexpr Money(const Money&) noexcept = default;
        Money& operator=(const Money&) noexcept = default;
        ~Money() = default;

        /* If this class can be a base class, it would need a virtual destructor.
         * otherwise, trivial destruction suffices.
         *
         * Theses are constexpr, but not noexcept, because they could throw a
         * std::overflow_error or std::underflow_error exception.
         */
        constexpr Money operator+(const Money&) const;
        constexpr Money operator-(const Money&) const;

        // This should be named in snake_case not in camelCase.
        std::string to_string() const;

        /* returns the quantity dominated in pounds, rounded to the nearst penny.
         * You might throw an exception rather than return an incorrectly
         * rounded result.
         */
        constexpr long double to_pounds() const noexcept;

        /* Returns only the part of the currency string beginning with the
         * point. E.g. for 12.34, returns 0.34.
         */
        constexpr double pence() const noexcept;

        static constexpr int pence_per_GBP = 100;

};

// This only needs to be friend if it uses an interface that isn't public
std::ostream& operator<<(std::ostream&, Money);
// unimplemented
std::istream& operator>>(std::istream&, Money);

// User defined llteral for currency in pounds, e.g. 12.34_L.
constexpr Money operator""_L (long double);
// User defined literal for currency in pence, e.g. 56_p.
constexpr Money operator""_p (long double);

#endif /* ifndef __MONEY_H__ */
