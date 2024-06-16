#pragma once
#include <string>
#include <fstream>
using namespace std;
namespace wqllyx
{
    class Logger
    {
    public:
        enum Level 
        {
            DEBUG = 0,
            INFO,
            WARN,
            ERROR,
            FATAL,
            LEVEL_COUNT
        };
        void log(Level level , const char *file, int line, const char *format, ...);

        static Logger *getInstance();

        void open(const string &filename);
        void close();

    private:
        Logger();
        ~Logger();
    private:
        string filenmae_;
        ofstream f_cout_;
        static const char *s_level_[LEVEL_COUNT];
        static Logger *instance_;
    };
} // namespace wqllyx
