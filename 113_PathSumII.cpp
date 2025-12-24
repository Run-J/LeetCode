/**
 * Overall Logic:
 * This solution uses DFS with backtracking.
 * 1. Add the current node to the path.
 * 2. If it's a leaf node and the value matches the remaining sum, record the path.
 * 3. Recursively explore children.
 * 4. Pop the node (backtrack) to keep the shared 'path' vector clean for other branches.
*/

class Solution {
public:
    void traversal(TreeNode* node, int count, vector<vector<int>>& results, vector<int>& path) {
        // Validation handles empty root or reaching past leaf nodes
        if (node == NULL) return;

        // 1. CHOOSE: Register current node in the shared path
        path.push_back(node->val);

        // 2. CHECK GOAL: Leaf node reached with the target remaining sum
        if (node->left == NULL && node->right == NULL && node->val == count) {
            results.push_back(path);
        }

        // 3. EXPLORE: Standard DFS to children
        if (node->left) traversal(node->left, count - node->val, results, path);
        if (node->right) traversal(node->right, count - node->val, results, path);

        // 4. BACKTRACK: Clean up 'path' before returning to the parent caller
        path.pop_back();
    }


    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> results;
        vector<int> path;
      
        traversal(root, targetSum, results, path);
        return results;
    }
};
