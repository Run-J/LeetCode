/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

// 只有当左右孩子都为空的时候，才说明遍历的最低点了。如果其中一个孩子为空则不是最低点
class Solution {
public:
    int minDepth(TreeNode* root) {
        
        int minDepth = 0;
        if (root == NULL) return minDepth;
        queue<TreeNode*> que;
        que.push(root);

        while (!que.empty()) {
            minDepth++;
            int rowSize = que.size();

            for (int i = 0; i < rowSize; i++) {
                TreeNode* node = que.front();
                que.pop();

                if (node->left == NULL && node->right == NULL) return minDepth;
                if (node->left) que.push(node->left);
                if (node->right) que.push(node->right);
            }
        }

        return minDepth;

    }
};