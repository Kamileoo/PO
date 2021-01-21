#ifndef STOPPER_H
#define STOPPER_H

#include <iostream>
#include <chrono>
#include <iomanip>

using namespace std;

class Stopper{
public:
    Stopper();
    ~Stopper();

    bool start();
    bool stop();
    bool reset();
    void display();
    
protected:
    std::chrono::time_point<std::chrono::high_resolution_clock> *startP;
    bool started;
    //std::chrono::steady_clock::time_point *endP;
    std::chrono::time_point<std::chrono::high_resolution_clock> *endP;
    bool stopped;
    double *time;
};


#endif /* !STOPPER_H */