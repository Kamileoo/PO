#ifndef LOGGER_H
#define LOGGER_H

#include <iostream>
#include <chrono>
#include <iomanip>

using namespace std;

class Logger{
public:
    Logger(bool debug = 0);
    void log(string data) const;
protected:
    bool debug;
};


#endif /* !LOGGER_H */