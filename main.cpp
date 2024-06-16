#include "Logger.h"
#include<iostream>
using namespace wqllyx;
using namespace std;
int main()
{
    Logger::getInstance()->open("./README.md");

    return 0;
}
