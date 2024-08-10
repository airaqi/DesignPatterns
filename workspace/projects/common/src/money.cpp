#include "money.h"

#include <cmath>
#include <iomanip>
#include <sstream>
#include <stdexcept>
#include <string>

using namespace std::literals::string_literals;

static const std::string invalid_arg_msg = "Monetry quantity out of range.";
static const std::string overflow_msg = "Monetry overflow";
static const std::string underflow_msg = "Monetry underflow";

/* Converts the quantity in GBP to the internal representation, ot throws a
 * std::invalid argument exception. rounds to the nearest mill.
 */
constexpr Money::Money(const long double pounds) 
{
    /* Refactored so that a NaN value will fall through this test correctly
     * raise an exception, rather than, as before, be spuriously converted.
     * On an implementation where the preceision of long  double is less than that
     * of long long int, such as MSVC, the 
     */

}


