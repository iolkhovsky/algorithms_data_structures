#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

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

ostream& operator<<(ostream&os, const TreeNode& root) {
    os << "===== Tree =====\n";
    queue<const TreeNode*> fifo;
    fifo.push(&root);

    int cnt = 0;
    int level = 0;
    while (!fifo.empty()) {
        const auto* pnode = fifo.front();
        fifo.pop();
        if (++cnt == (0x1 << level)) {
            os << "\n";
            level++;
        }
        if (pnode) {
            os << pnode->val << " ";
            fifo.push(pnode->left);
            fifo.push(pnode->right);
        } else {
            os << "null" << " ";
        }
    }
    os << "\n";
    return os;
}

int main(int argc, char** argv) {
    vector<int> nums = {-10, -3, 0, 5, 9};

    TreeNode* root = Solution().sortedArrayToBST(nums);
    cout << *root;
}