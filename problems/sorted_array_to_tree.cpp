#include <iostream>
#include <vector>
#include <queue>

#include "problems/tree_utils.hpp"

/*
https://leetcode.com/problems/convert-sorted-array-to-binary-search-tree/
*/

using namespace std;

class Solution {
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return recursivelyBuild(nums, 0, static_cast<int>(nums.size()));
    }
    TreeNode* recursivelyBuild(const std::vector<int>& nums, int start, int end) {
        TreeNode* root = nullptr;
        if (end - start > 0) {
            root = new TreeNode();
            int median = (end - 1 - start) / 2;
            root->val = nums[start + median];
            root->left = recursivelyBuild(nums, start, start + median);
            root->right = recursivelyBuild(nums, start + median + 1, end);
        }
        return root;
    }
};

int main(int argc, char** argv) {
    vector<int> nums = {-10, -3, 0, 5, 9};

    TreeNode* root = Solution().sortedArrayToBST(nums);
    cout << *root;

    return 0;
}
