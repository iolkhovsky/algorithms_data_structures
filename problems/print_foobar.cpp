#include <iostream>
#include <functional>
#include <future>
#include <thread>
#include <chrono>

using namespace std;

void pPrintFoo() {
    std::this_thread::sleep_for(std::chrono::milliseconds(100));
    std::cout << "foo\n";
}

void pPrintBar() {
    std::this_thread::sleep_for(std::chrono::milliseconds(100));
    std::cout << "bar\n";
}

class FooBar {
public:
    FooBar(int n) : n(n) {}

    void foo(function<void()> printFoo) {
        for (int i = 0; i < n; i++) {
            while (true)
            {
                lock_guard<mutex> l(m);
                if (foo_cntr == bar_cntr) {
                    // printFoo() outputs "foo". Do not change or remove this line.
                    printFoo();
                    foo_cntr++;
                    break;
                }
            }
        }
    }

    void bar(function<void()> printBar) {
        for (int i = 0; i < n; i++) {
            while(true) {
                lock_guard<mutex> l(m);
                if (foo_cntr > bar_cntr) {
                    // printBar() outputs "bar". Do not change or remove this line.
                    printBar();
                    bar_cntr++;
                    break;
                }
            }
        }
    }
private:
    int n;
    int foo_cntr = 0;
    int bar_cntr = 0;
    mutex m;
};

int main(int argc, char** argv) {
    FooBar a(5);
    auto f2 = std::async([&a] () { a.bar(pPrintBar); });
    auto f1 = std::async([&a] () { a.foo(pPrintFoo); });
    
    std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    f1.get();
    f2.get();
    return 0;
}