#include <iostream>
#include <string>
#include <unordered_set>

using namespace std;

istream& operator>>(istream& is, unordered_multiset<char>& data) {
    char c;
    while(is.get(c) && c != '\n') {
        data.insert(c);
    }
    return is;
}

int main(int argc, char** argv) {
    unordered_multiset<char> a;
    cin >> a;
    bool processing = true;
    int cnt = a.size();
    char c;
    while(cin.get(c) && c != '\n') {
        cnt--;
        if (cnt < 0)
            processing = false;
        if (processing) {
            auto it = a.find(c);
            if (it != a.end())
                a.erase(it);
            else
                processing = false;
        }
    }
    cout << (processing && a.empty() ? 1 : 0) << endl;
    return 0;
}
