#include "Logger.h"
#include <fstream>
#include <stdexcept>
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

void Logger::open(const string &filename)
{
    filenmae_ = filename;

    f_cout_.open(filename, ios::app);
    if (!f_cout_)
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
