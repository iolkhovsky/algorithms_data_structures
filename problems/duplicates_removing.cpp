#include <iostream>

using namespace std;

int main(int argc, char** argv) {
    int n;
    cin >> n;
    if (n) {
        int prev, cur;
        cin >> prev;
        cout << prev << "\n";
        for (int i = 1; i < n; i++) {
            cin >> cur;
            if (cur != prev)
                cout << cur << "\n";
            prev = cur;
        }
    }
    return 0;   
}
