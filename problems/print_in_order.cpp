#include <iostream>
#include <functional>
#include <future>
#include <thread>
#include <chrono>

void fPrintFirst() { 
    int acc = 0;
    for (int i = 0; i < 10000000; i++)
        acc += i;
    std::cout << "first" << acc; 
}

void fPrintSecond() { 
    int acc = 0;
    for (int i = 0; i < 1000000; i++)
        acc += i;
    std::cout << "second" << acc; 
}

void fPrintThird() { 
    int acc = 0;
    for (int i = 0; i < 100000; i++)
        acc += i;
    std::cout << "third" << acc; 
}

using namespace std;

class Foo {
public:
    Foo() {

    }

    void first(function<void()> printFirst) {
        lock_guard<mutex> l(m);
        // printFirst() outputs "first". Do not change or remove this line.
        printFirst();
        state++;
    }

    void second(function<void()> printSecond) {
        while (true) {
            lock_guard<mutex> l(m);
            if (state == 1) {
                // printSecond() outputs "second". Do not change or remove this line.
                printSecond();
                state++;
                break;
            }
        }
    }

    void third(function<void()> printThird) {
        while (true) {
            lock_guard<mutex> l(m);
            if (state == 2) {
                // printSecond() outputs "second". Do not change or remove this line.
                printThird();
                state++;
                break;
            }
        }
    }
private:
    std::mutex m;
    int state = 0;
};

int main(int argc, char** argv) {
    Foo foo;
    auto f3 = std::async([&foo] () { foo.third(fPrintThird); });
    auto f2 = std::async([&foo] () { foo.second(fPrintSecond); });
    auto f1 = std::async([&foo] () { foo.first(fPrintFirst); });
    

    std::this_thread::sleep_for(std::chrono::milliseconds(100));

    f1.get();
    f2.get();
    f3.get();
    return 0;
}