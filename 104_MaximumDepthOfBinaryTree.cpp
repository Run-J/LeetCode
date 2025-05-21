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

// 用队列辅助层序遍历，记录层数
class Solution {
public:
    int maxDepth(TreeNode* root) {
        
        int maxDepth = 0;
        if (root == NULL) return maxDepth; // maxDepth is 0
        queue<TreeNode*> que;
        que.push(root);

        while (!que.empty()) {
            maxDepth++;
            int rowSize = que.size();

            for (int i = 0; i < rowSize; i++) {
                TreeNode* node = que.front();
                que.pop();

                if (node->left) que.push(node->left);
                if (node->right) que.push(node->right);
            }
        }

        return maxDepth;
    }
};