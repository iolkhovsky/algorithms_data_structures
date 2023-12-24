#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char** argv) {
    int seqLen;
    cin >> seqLen;
    bool curValue;
    int cnt = 0;
    int result = 0;
    for (int i = 0; i < seqLen; i++) {
        cin >> curValue;
        cnt = curValue ? ++cnt : 0;
        result = std::max(cnt, result);
    }
    cout << std::max(cnt, result);
    return 0;
}
