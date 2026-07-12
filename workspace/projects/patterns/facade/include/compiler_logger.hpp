#ifndef __COMPILER_LOGGER_H__
#define __COMPILER_LOGGER_H__ 

#include <chrono>
#include <ctime>
#include <format>
#include <iomanip>
#include <iostream>
#include <ostream>
#include <sstream>
#include <string>

namespace ilog {

    enum class LogLevel {
        DEBUG,
        INFO, 
        WARN,
        ERROR,
        CRITIC,
        NONE
    };

    inline std::string to_string(LogLevel level) 
    {
        switch(level)
        {
            case LogLevel::DEBUG:   return "DEBUG";
            case LogLevel::INFO:    return "INFO";
            case LogLevel::WARN:    return "WARN";
            case LogLevel::ERROR:   return "ERROR";
            case LogLevel::CRITIC:  return "CRITICAL";
            default:                return "NONE";
        }
    }

    class LogRecord {
        using time_point = std::chrono::time_point<std::chrono::nanoseconds>;

        public:
            time_point   _time;
            std::string  _class;
            LogLevel    _level;
            std::string _description;

    };

    class LogStream : public std::stringbuf
    {
        protected:
            LogLevel _level;
            std::ostringstream oss;
            // std::ostream os;

        public:
            LogStream() : _level(LogLevel::INFO) {}

            std::string timestamp() {
                    auto now = std::chrono::system_clock::now();
                    auto now_time_t = std::chrono::system_clock::to_time_t(now);
                    auto time = std::put_time(localtime(&now_time_t), "%y-%m-%d %h:%m:%s");
                    return std::format("{0:%F_%T}", now);

            }

            int sync() override {
                std::string log_message = str();
                if (!log_message.empty()) {
                    auto now = std::chrono::system_clock::now();
                    auto now_time_t = std::chrono::system_clock::to_time_t(now);

                    oss << "[" << std::put_time(std::localtime(&now_time_t), "%y-%m-%d %h:%m:%s") << "] " 
                        << "[" << to_string(_level) << "] "
                        << log_message 
                        << std::endl;

                    //std::cout << oss.str();
                    
                    // Clear the internal string buffer after flushing
                    str(""); 
                }
                return 0;
            }

        public:
            void level(LogLevel l) { _level = l; }

            std::string to_str() const { 
                return oss.str(); 
            }

            

    };

    inline LogStream loggerStream;
    inline std::ostream logger(&loggerStream);
    inline std::ostream& lout = logger;
    inline std::ostream& lerr = logger;
}
#endif /* ifndef __COMPILER_LOGGER_H__ */
