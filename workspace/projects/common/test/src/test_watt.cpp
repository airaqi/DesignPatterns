#include "watt.h"
#include <doctest/doctest.h>
#include <stdexcept>

TEST_CASE("Test Watt") {
    Watt w1;
    Watt w2(10);
    Watt w3(20);
    Watt w4(30);
    Watt w5(10);

    SUBCASE("value") {
        CHECK_EQ(0, w1.value());
        CHECK_EQ(10, w2.value());
        CHECK_EQ(20, w3.value());
        CHECK_EQ(30, w4.value());
    }

    SUBCASE("operator==") {
        CHECK_EQ(true, w2 == w5);
        CHECK_EQ(false, w1 == w2);
    }

    SUBCASE("operator+") {
        CHECK_EQ(w4, w2 + w3);
    }

    SUBCASE("operator-") {
        CHECK_EQ(w3, w4 - w2);
    }

    SUBCASE("operator*") {
        CHECK_EQ(w3, w2 * 2);
        CHECK_EQ(w2, w3 * 0.5);
    }

    SUBCASE("operator/") {
        CHECK_EQ(w2, w3 / 2);
        CHECK_THROWS_AS(w2 / 0, std::runtime_error);
    }
}
