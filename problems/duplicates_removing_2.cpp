#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.empty())
            return 0;   
        int k = 1;
        int prev = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] != prev) {
                prev = nums[i];
                if (i != k)                   
                    swap(nums[i], nums[k]);
                k++;
            }
        }
        nums.resize(k);
        return k;
    }
};

ostream& operator<<(ostream& os, const vector<int>& data) {
    cout << "[";
    for (auto d: data) {
        cout << d << ", ";
    }
    cout << "]" << endl;
    return os;
}

int main(int argc, char** argv) {
    vector<int> data = {0, 0, 1, 1, 1, 2, 2, 3, 3, 4};
    Solution().removeDuplicates(data);
    cout << data;
    return 0;
}
