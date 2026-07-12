#include "compiler_logger.hpp"
#include "doctest_main.h"
#include <iostream>
#include <ostream>
#include <string>
#include <vector>

TEST_CASE("compiler_logger")
{
  SUBCASE("log line")
  {
    std::string msg = "log one line";
    ilog::lout << msg;
    std::string logs = ilog::loggerStream.str();
    std::cout << ">>>> compile log: " << logs << std::endl;
    CHECK_EQ(msg, logs);
  }

  SUBCASE("log multiple lines")
  {
    std::vector<std::string> msgs = { "log info one", "log info two" };
    std::string logs;

    for (const std::string& msg : msgs) 
    {
      ilog::lout << msg;
      logs.append(msg);
    }

    std::string log = ilog::loggerStream.str();
    std::cout << ">>>> comile logs: " << log << std::endl;
    CHECK_EQ(logs, log);
  }
}
