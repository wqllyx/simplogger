#include "Logger.h"
#include <fstream>
#include <stdexcept>
#include <ctime>
#include <strings.h>
#include <iostream>
#include <cstdarg>
using namespace wqllyx;

const char *Logger::s_level_[LEVEL_COUNT] = {
    "DEBUG",
    "INFO",
    "WARN",
    "ERROR",
    "FATAL"};

Logger *Logger::instance_ = nullptr;

/**
 * @brief 获取单例
 *
 * @return Logger*
 */
Logger *Logger::getInstance()
{
    if (!instance_)
        instance_ = new Logger();
    return instance_;
}

void Logger::log(Level level, const char *file, int line, const char *format, ...)
{
    if (!f_cout_.is_open())
        throw std::logic_error("open file failed!" + filenmae_);
    std::time_t ticks = std::time(nullptr);
    std::tm *localtimes = localtime(&ticks);
    char timestamp[32];
    bzero(timestamp, sizeof(timestamp));
    std::strftime(timestamp, sizeof(timestamp), "%Y-%m-%d %H:%M:%S", localtimes);
    // std::cout << timestamp << std::endl;
    // std::cout << file << std::endl;
    // std::cout << line << std::endl;
    // std::cout << format << std::endl;
    const char *fmt = "%s %s %s:%d ";
    int size = snprintf(nullptr, 0, fmt, timestamp, s_level_[level], file, line);
    if (size > 0)
    {
        char *buffer = new char[size + 1];
        bzero(buffer, sizeof(buffer));
        snprintf(buffer, size + 1, fmt, timestamp, s_level_[level], file, line);
        f_cout_ << buffer;
        delete buffer;
    }

    va_list arg_ptr;
    va_start(arg_ptr, format);
    size = vsnprintf(nullptr, 0, format, arg_ptr);
    va_end(arg_ptr);
    if (size > 0)
    {
        char *content = new char[size + 1];
        va_start(arg_ptr, format);
        vsnprintf(content, size + 1, format, arg_ptr);
        va_end(arg_ptr);
        f_cout_ << content;
    }
    f_cout_ << '\n';
    f_cout_.flush();
}

void Logger::open(const string &filename)
{
    filenmae_ = filename;

    f_cout_.open(filename, ios::app);
    if (!f_cout_.is_open())
        throw std::logic_error("open file failed!" + filenmae_);
}

void Logger::close()
{
    f_cout_.close();
}
Logger::Logger()
{
}
Logger::~Logger()
{
}
