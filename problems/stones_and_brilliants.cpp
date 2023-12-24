#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_set>

using namespace std;

istream& operator>>(istream& is, unordered_set<char>& data) {
    char c;
    while(is.get(c) && c != '\n')
        data.insert(c);
    return is;
}

int main(int argc, char** argv) {
    unordered_set<char> j;
    string s;
    cin >> j >> s;
    cout << std::count_if(s.begin(), s.end(), [&j](const char& c) {return j.count(c);});
    return 0;
}
