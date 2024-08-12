#include <doctest/doctest.h>
#include <stdexcept>
#include "currency.h"

TEST_CASE("Currency") {
   
    Currency c1;
    Currency c2(100);
    Currency c3(100, "US Dollar", "USD");
    Currency c4(100);
    Currency c5(50);

    SUBCASE("value") {
        CHECK_EQ(0, c1.value());
        CHECK_EQ(100, c2.value());
        CHECK_EQ(100, c3.value());
    }

    SUBCASE("name") {
        CHECK_EQ("Egyptian Pound", c1.name());
        CHECK_EQ("Egyptian Pound", c2.name());
        CHECK_EQ("US Dollar", c3.name());
    }

    SUBCASE("symbol") {
        CHECK_EQ("EGP", c1.iso_code());
        CHECK_EQ("EGP", c2.iso_code());
        CHECK_EQ("USD", c3.iso_code());
    }

    SUBCASE("compatible") {
        CHECK_EQ(true, c1.compatible(c2));
        CHECK_EQ(false, c1.compatible(c3));
    }

    SUBCASE("operator==") {
        CHECK_EQ(true, c2 == c4);
        CHECK_EQ(false, c1 == c2);
    }

    SUBCASE("operator+") {
        CHECK_EQ(Currency(150), c2 + c5);
    }

    SUBCASE("operator-") {
        CHECK_EQ(Currency(50), c2 - c5);
    }

    SUBCASE("operator*") {
        CHECK_EQ(Currency(200), c2 * 2);
        CHECK_EQ(Currency(50), c2 * 0.5);
    }

    SUBCASE("operator/") {
        CHECK_EQ(Currency(50), c2 / 2);
        CHECK_THROWS_AS((c2 / 0), std::runtime_error);
    }

    SUBCASE("to_string") {
        CHECK_EQ("EGP 100.00", c2.to_string());
    }

}
