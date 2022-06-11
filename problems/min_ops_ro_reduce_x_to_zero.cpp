#include <iostream>
#include <vector>
#include <algorithm>

/*
https://leetcode.com/problems/minimum-operations-to-reduce-x-to-zero/
*/

using namespace std;

class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        if (nums.empty())
            return (x == 0) ? 0 : -1;
        return getRecursively(nums, 0, static_cast<int>(nums.size()), x, 0);
    }
    int getRecursively(const vector<int>& nums,
                       int begin,
                       int end,
                       int target,
                       int steps) {
        if (target == 0)
            return steps;
        int size = end - begin;
        if (size == 0)
            return -1;
        if (size == 1)
            return (nums[begin] == target) ? steps + 1 : -1;
        
        int min = *std::min_element(nums.begin(), nums.end());
        if (target < min)
            return -1;

        return getMinimum(
            getRecursively(nums, begin + 1, end, target - nums[begin], steps + 1),
            getRecursively(nums, begin, end - 1, target - nums[end-1], steps + 1)
        );
    }
    int getMinimum(int a, int b) {
        if ((a > 0) && (b > 0))
            return std::min(a, b);
        else if (a > 0)
            return a;
        else if (b > 0)
            return b;
        else
            return -1;
    }
};

int main(int argc, char** argv) {
    vector<int> example1 = {1, 1, 4, 2, 3};
    cout << Solution().minOperations(example1, 5) << "\n";

    vector<int> example2 = {5, 6, 7, 8, 9};
    cout << Solution().minOperations(example2, 4) << "\n";

    vector<int> example3 = {3, 2, 20, 1, 1, 3};
    cout << Solution().minOperations(example3, 10) << "\n";

    vector<int> example4 = {
        1241,8769,9151,3211,2314,8007,3713,5835,2176,8227,5251,9229,904,1899,5513,7878,8663,3804,
        2685,3501,1204,9742,2578,8849,1120,4687,5902,9929,6769,8171,5150,1343,9619,3973,3273,
        6427,47,8701,2741,7402,1412,2223,8152,805,6726,9128,2794,7137,6725,4279,7200,5582,9583,
        7443,6573,7221,1423,4859,2608,3772,7437,2581,975,3893,9172,3,3113,2978,9300,6029,4958,
        229,4630,653,1421,5512,5392,7287,8643,4495,2640,8047,7268,3878,6010,8070,7560,8931,76,
        6502,5952,4871,5986,4935,3015,8263,7497,8153,384,1136
    };
    cout << Solution().minOperations(example4, 894887480) << "\n";
}