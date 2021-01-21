#include "Stopper.h"

Stopper::Stopper() {
    startP = nullptr;
    endP = nullptr;
    time = nullptr;
    started = 0;
    stopped = 0;
}

Stopper::~Stopper() {
    delete startP;
    delete endP;
    delete time;
}

bool Stopper::start() {
    if(started == 1 && stopped == 1) { reset(); }
    if(started == 0 && stopped == 0) {
        startP = new std::chrono::time_point<std::chrono::high_resolution_clock>(chrono::high_resolution_clock::now());
        //startPP = chrono::high_resolution_clock::now();
        started = 1;
        return true;
    }
    else { return false; }
}

bool Stopper::stop() {
    if(started == 1 && stopped == 0) {
        endP = new std::chrono::time_point<std::chrono::high_resolution_clock>(chrono::high_resolution_clock::now());
        //endP = new std::chrono::steady_clock::time_point;
        //*endP = chrono::high_resolution_clock::now();
        //endP = new std::chrono::steady_clock::time_point(chrono::high_resolution_clock::now());
        //endP = chrono::high_resolution_clock::now();
        stopped = 1;

        std::chrono::duration<double> chronoTime = *endP-*startP;
        time = new double(chronoTime.count());
        //time = chronoTime.count();

        return true;
    }
    else { return false; }
}

bool Stopper::reset() {
    started = 0;
    stopped = 0;
    delete startP;
    startP = nullptr;
    delete endP;
    endP = nullptr;
    delete time;
    time = nullptr;
    return true;
}

void Stopper::display() {
    if(started == 1 && stopped == 1) {
        cout << "Time: " << *time << "s" << endl;
    }
}