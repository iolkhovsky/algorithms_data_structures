#include <iostream>
#include <functional>
#include <vector>
#include <future>
#include <chrono>

using namespace std;

void defaultPrintFunction(int i) {
    std::this_thread::sleep_for(std::chrono::milliseconds(100));
    cout << i << std::endl;
}

class ZeroEvenOdd {
public:
    ZeroEvenOdd(int n)
    : target(n)
    , num(0)
    , previous_is_zero(false) {
        cv.notify_all();
    }

    void zero(function<void(int)> printNumber) {
        run(
            [this] () {
                return  (!previous_is_zero) || completed();
            },
            [&] () {
                printNumber(0);
                previous_is_zero = true;
            }
        );
    }

    void even(function<void(int)> printNumber) {
        run(
            [this] () {
                return ((num % 2) && previous_is_zero) || completed();
            },
            [&] () {
                printNumber(++num);
                previous_is_zero = false;
            }
        );
    }

    void odd(function<void(int)> printNumber) {
        run(
            [this] () {
                return ((num % 2 == 0) && previous_is_zero) || completed();
            },
            [&] () {
                printNumber(++num);
                previous_is_zero = false;
            }
        );
    }
private:
    int target;
    int num;
    bool previous_is_zero;
    mutex m;
    condition_variable cv;

    bool completed() {
        return num >= target;
    }

    void wait_for(function<bool()> predicate) {
        unique_lock<mutex> l(m);
        cv.wait(l, predicate);
    }

    void run(function<bool()> condition, function<void()> routine) {
        while(true) {
            wait_for(condition);
            lock_guard<mutex> locker(m);
            if (completed())
                break;
            routine();
            cv.notify_all(); 
        }
    }
};

int main(int argc, char** argv) {
    ZeroEvenOdd p(4);
    vector<future<void>> f;
    f.push_back(
        async([&p] () { p.even(defaultPrintFunction); })
    );
    f.push_back(
        async([&p] () { p.zero(defaultPrintFunction); })
    );
    f.push_back(
        async([&p] () { p.odd(defaultPrintFunction); })
    );

    std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    for (auto& item : f)
        item.get();

    return 0;
}