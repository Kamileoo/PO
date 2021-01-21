#include "Logger.h"

Logger::Logger(bool debug) {
    this->debug = debug;
}

void Logger::log(string data) const {
    auto now = chrono::system_clock::now();
    auto now_timet = chrono::system_clock::to_time_t(now);
    auto now_local = localtime(&now_timet);
    auto cur = put_time(now_local, "%d.%m.%Y %H:%M:%S");
    if(debug == 1) { cout << cur << ": " << data << endl; }
}