#include <iostream>
#include <string>

using namespace std;

void generate_sequence(int size, int acc = 0, string seq = {}) {
    if (seq.size() < size) {
        if (size - seq.size() >= 2) {
            generate_sequence(size, acc+1, seq + '(');
        }
        if (acc > 0) {
            generate_sequence(size, acc-1, seq + ')');
        }
    }
    if (seq.size() == size && acc == 0) {
        for (auto c: seq)
            cout << c;
        cout << "\n";
    }
}

int main(int argc, char** argv) {
    int n;
    cin >> n;
    generate_sequence(2*n);
    return 0;
}
