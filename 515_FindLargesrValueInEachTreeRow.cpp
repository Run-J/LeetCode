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

// level traversal, get maxValue of each level
class Solution {
public:
    vector<int> largestValues(TreeNode* root) {

        vector<int> result;
        if (root == NULL) return result;

        queue<TreeNode*> que;
        que.push(root);

        while (!que.empty()) {
            int rowSize = que.size();
            int maxOfEachRow = 0;

            for (int i = 0; i < rowSize; i++) {
                TreeNode* node = que.front();
                que.pop();

                if (i == 0) maxOfEachRow = node->val;
                else if (node->val > maxOfEachRow) maxOfEachRow = node->val;

                if (node->left) que.push(node->left);
                if (node->right) que.push(node->right);
            }

            result.push_back(maxOfEachRow);
        }

        return result;
    }
};