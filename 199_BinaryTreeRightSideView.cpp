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
    vector<int> rightSideView(TreeNode* root) {
        
        vector<int> result;
        queue<TreeNode*> que;

        if (root == NULL) return result;

        que.push(root);

        while (!que.empty()) {
            int rowSize = que.size();

            while (rowSize--) {
                TreeNode* node = que.front();
                que.pop();

                if (rowSize == 0) result.push_back(node->val); // 只记录每一行的最后（最右侧的节点value，便是从右往左看的值
                if (node->left) que.push(node->left);
                if (node->right) que.push(node->right);
            }
        }

        return result;
    }
};