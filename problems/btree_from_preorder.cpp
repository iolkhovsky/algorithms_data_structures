#include <algorithm>
#include <cassert>
#include <iostream>
#include <iterator>
#include <vector>

#include "problems/tree_utils.hpp"

/*
https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/
*/

using namespace std;

class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return buildRecursively(preorder, 0, preorder.size(), inorder, 0, inorder.size());
    }
    TreeNode* buildRecursively(const vector<int>& preorder, 
                               int preorder_begin,
                               int preorder_end,
                               const vector<int>& inorder,
                               int inorder_begin,
                               int inorder_end) {
        int preorder_size = preorder_end - preorder_begin;
        int inorder_size = inorder_end - inorder_begin;
        assert(preorder_size == inorder_size);
        if (preorder_size == 0)
            return nullptr;
        TreeNode* root = new TreeNode();
        root->val = preorder[preorder_begin];

        int inorder_begin_left = inorder_begin;
        int inorder_end_left = 0;
        int inorder_begin_right = 0;
        int inorder_end_right = inorder_end;

        auto search_begin = inorder.begin() + inorder_begin;
        auto search_end = inorder.begin() + inorder_end;
        auto root_it = std::find(search_begin, search_end, root->val);
        assert(root_it != search_end);
        int root_idx = inorder_begin + static_cast<int>(std::distance(search_begin, root_it));
        inorder_end_left = root_idx;
        inorder_begin_right = root_idx + 1; 

        int left_size = inorder_end_left - inorder_begin_left;
        int preorder_begin_left = preorder_begin + 1;
        int preorder_end_left = preorder_begin_left + left_size;
        int preorder_begin_right = preorder_end_left;
        int preorder_end_right = preorder_end;

        root->left = buildRecursively(
            preorder,
            preorder_begin_left,
            preorder_end_left,
            inorder,
            inorder_begin_left,
            inorder_end_left);
        root->right = buildRecursively(
            preorder,
            preorder_begin_right,
            preorder_end_right,
            inorder,
            inorder_begin_right,
            inorder_end_right);
        return root;
    }
};

int main(int argc, char** argv) {
    vector<int> preorder = {3,9,20,15,7};
    vector<int> inorder = {9,3,15,20,7};
    TreeNode* root = Solution().buildTree(preorder, inorder);
    cout << *root;
    return 0;
}