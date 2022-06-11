#include <iostream>
#include <functional>
#include <future>
#include <thread>
#include <chrono>
#include <vector>

using namespace std;

void printHydrogen() {
    std::this_thread::sleep_for(std::chrono::milliseconds(50));
    std::cout << "H";
}

void printOxygen() {
    std::this_thread::sleep_for(std::chrono::milliseconds(50));
    std::cout << "O";
}

class H2O {
public:
    H2O() {}

    void hydrogen(function<void()> releaseHydrogen) {
        while(true) {
            lock_guard<mutex> l(m);
            if (h_cntr < 2) {
                // releaseHydrogen() outputs "H". Do not change or remove this line.
                releaseHydrogen();
                h_cntr++;

                if ((h_cntr == 2) && (o_cntr == 1)) {
                    h_cntr = 0;
                    o_cntr = 0;
                }
                break;
            }
        }
    }

    void oxygen(function<void()> releaseOxygen) {
        while(true) {
            lock_guard<mutex> l(m);
            if (o_cntr < 1) {
                // releaseOxygen() outputs "O". Do not change or remove this line.
                releaseOxygen();
                o_cntr++;

                if ((h_cntr == 2) && (o_cntr == 1)) {
                    h_cntr = 0;
                    o_cntr = 0;
                }
                break;
            }
        }
    }
private:
    int h_cntr = 0;
    int o_cntr = 0;
    mutex m;
};

int main(int argc, char** argv) {
    H2O builder;

    vector<future<void>> futures;
    for (int i = 0; i < 4; i++) {
        futures.push_back(
            std::async([&builder] () { builder.oxygen(printOxygen); })
        );
    }
    for (int i = 0; i < 8; i++) {
        futures.push_back(
            std::async([&builder] () { builder.hydrogen(printHydrogen); })
        );
    }
    
    std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    for (auto& f : futures)
        f.get();
    return 0;
}