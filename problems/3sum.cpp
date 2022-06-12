#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int sz = static_cast<int>(nums.size());
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());

        for (int i = 0; i < sz; i++) {
            if (i && ((nums[i - 1] == nums[i])))
                continue;
            int a = nums[i];
            unordered_set<int> seen;
            for (int j = i + 1; j < sz; j++) {
                int b = nums[j];
                if (seen.count(-1 * (a + b))) {
                    ans.push_back({a, b, -1 * (a + b)});
                    while ((j + 1 < sz) && (nums[j + 1] == nums[j]))
                        j++;
                }
                seen.insert(b);
            }
        }

        return ans;
    }
};

int main(int argc, char** argv) {
    vector<int> data = {-1,0,1,2,-1,-4};
    auto res = Solution().threeSum(data);
    // for (const auto& comb : res) {
    //     for (const auto item : comb) {
    //         cout << item << ", ";
    //     }
    //     cout << "\n";
    // }

    vector<int> data2 = {0, 0, 0, 0};
    res = Solution().threeSum(data2);
    for (const auto& comb : res) {
        for (const auto item : comb) {
            cout << item << ", ";
        }
        cout << "\n";
    }
    return 0;
}