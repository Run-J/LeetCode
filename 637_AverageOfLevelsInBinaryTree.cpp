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
    vector<double> averageOfLevels(TreeNode* root) {
        
        vector<double> result;
        if (root == NULL) return result;

        queue<TreeNode*> que;
        que.push(root);

        while (!que.empty()) {
            int rowSize = que.size();
            double rowSum = 0;

            for (int i = 0; i < rowSize; i++) {
                TreeNode* node = que.front();
                que.pop();

                rowSum += node->val;
                if (node->left) que.push(node->left);
                if (node->right) que.push(node->right);
            }

            double rowAvg = rowSum / rowSize;
            result.push_back(rowAvg);
        }

        return result;
    }
};