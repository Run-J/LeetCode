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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        
        vector<vector<int>> result;
        queue<TreeNode*> que;

        if (root == NULL) return result;

        que.push(root);

        while (!que.empty()) {
            int rowSize = que.size();
            vector<int> row;

            while (rowSize--) {
                TreeNode* node = que.front();
                que.pop();

                row.push_back(node->val);
                if (node->left) que.push(node->left);
                if (node->right) que.push(node->right);
            }

            result.push_back(row);
        }

        reverse(result.begin(), result.end()); // 把从上往下层序遍历的result反转一下就是从下到上的层序遍历了
        return result;
    }
};