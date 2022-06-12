#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    vector<vector<string>> partition(string s) {
        int size = static_cast<int>(s.size());
        vector<vector<bool>> is_palidrome(size);
        for (auto& item : is_palidrome)
            item.assign(size, false);
        
        for (int j = size - 1; j >= 0; j--) {
            for (int i = j; i < size; i++) {
                if (i == j) {
                    is_palidrome[j][i] = true;
                } else if (j < size - 1) {
                    if (is_palidrome[j + 1][i - 1] && (s[i] == s[j])) {
                        is_palidrome[j][i] = true;
                    } else if (i > j) {
                        if ((s[i] == s[j]) && (j + 1 == i))
                            is_palidrome[j][i] = true;
                    }
                }
            }
        }
        
        vector<vector<string>> ans;
        generate(s, ans, is_palidrome, 0, {});
        return ans;
    }
    
    void generate(
        const string& s,
        vector<vector<string>>& ans,
        const vector<vector<bool>>& is_palindrome,
        int offset,
        vector<string> seq
    ) {
        int size = static_cast<int>(is_palindrome.size());
        if (offset >= size) {
            if (!seq.empty())
                ans.push_back(seq);
            return;
        }
        for (int i = 0; i < size; i++) {
            if (is_palindrome[offset][i]) {
                vector<string> buf(seq);
                buf.push_back({s.begin() + offset, s.begin() + i + 1});
                generate(s, ans, is_palindrome, i + 1, buf);
            }
        }
    }
};

int main(int argc, char** argv) {
    string s = "aab";

    auto ans = Solution().partition(s);
    for (const auto& partitioning : ans) {
        for (const auto& s : partitioning)
            cout << s << ", ";
        cout << "\n";
    }
    return 0;
}