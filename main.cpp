#include "Logger.h"
#include<iostream>
#include<fstream>
using namespace wqllyx;
using namespace std;
int main()
{
    Logger::getInstance()->open("log");
    Logger::getInstance()->log(Logger::DEBUG, __FILE__, __LINE__, "name is %s, age is %d", "jack",18);
    return 0;
}
