// Solution 1: Recursive (DFS)
// Logic: Use DFS to traverse the tree. 
// Update the result whenever a leaf node is found at a depth greater than the current maxDepth.
// traversal (Left before Right) ensures the first node at a new depth is the leftmost.
class Solution {
public:
    int maxDepth = INT_MIN; // Tracks the maximum depth reached
    int result = 0;         // Stores the value of the bottom-left node

    void traversal(TreeNode* node, int depth) {
        // Base case: If leaf node is reached, check if it's the deepest found so far
        if (node->left == NULL && node->right == NULL) {
            if (depth > maxDepth) {
                maxDepth = depth;
                result = node->val;
            }
            return;
        }

        // Recursive step with backtracking
        if (node->left != NULL) {
            depth++; 
            traversal(node->left, depth);
            depth--; // Backtrack
        }

        if (node->right != NULL) {
            depth++;
            traversal(node->right, depth);
            depth--; // Backtrack
        }
    }

    int findBottomLeftValue(TreeNode* root) {
        traversal(root, 0);
        return result;
    }
};


// Solution 2: Iterative (BFS / Level-Order)
// Logic: Use BFS (Level-Order Traversal) to process nodes level by level.
// The first node of the final row processed will be the result.
class Solution {
public:
    int findBottomLeftValue(TreeNode* root) {
        queue<TreeNode*> que;
        if (root != NULL) que.push(root);
        int result = 0;

        while (!que.empty()) {
            int size = que.size();

            for (int i = 0; i < size; i++) {
                TreeNode* node = que.front();
                que.pop();

                // Capture the first node of each level
                if (i == 0) result = node->val;

                if (node->left != NULL) que.push(node->left);
                if (node->right != NULL) que.push(node->right);
            }   
        }

        return result; // Last assigned value is the bottom-leftmost
    }
};
