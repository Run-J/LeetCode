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

class Solution {
public:
    // 层序遍历（广度优先遍历），按层从左到右遍历二叉树
    vector<vector<int>> levelOrder(TreeNode* root) {
        
        vector<vector<int>> result;       // 存储最终结果，每层是一个 vector<int>
        queue<TreeNode*> que;            // 辅助队列，用于 BFS 遍历每一层

        // 特判：空树直接返回空结果
        if (root == nullptr) return result;

        // 初始化：将根节点入队
        que.push(root);

        // 外层 while：按层处理，直到队列为空
        while (!que.empty()) {
            int queSize = que.size();     // 当前层的节点数量
            vector<int> row;              // 存储当前层的结果

            // 内层 while：处理当前层的所有节点
            while (queSize--) {
                TreeNode* node = que.front();
                que.pop();

                row.push_back(node->val); // 记录当前节点值

                // 把左右子节点加入队列，等待下一层处理
                if (node->left != nullptr) que.push(node->left);
                if (node->right != nullptr) que.push(node->right);
            }

            // 当前层处理完毕，加入结果
            result.push_back(row);
        }

        return result;
    }
};