#include <queue>

#include "tree_utils.hpp"

std::ostream& operator<<(std::ostream&os, const TreeNode& root) {
    os << "===== Tree =====\n";
    std::queue<const TreeNode*> fifo;
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
