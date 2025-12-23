// Solution 1 (Recursion)
// Logic: decrease the targetSum by subtracting the current node's value at each step.
// If we reach a leaf node and the remaining targetSum equals the leaf's value, a path exists.
class Solution {
public:

    bool hasPathSum(TreeNode* root, int targetSum) {
        if (root == NULL) return false;

        if (root->left == NULL && root->right == NULL) {
            return root->val == targetSum;
        }

        return hasPathSum(root->left, targetSum - root->val) ||
               hasPathSum(root->right, targetSum - root->val);
    }
};


// More clear version of solution 1 (Explicit Backtracking)
class Solution {
private:
    /**
     * @param cur: The current node we are visiting
     * @param count: The remaining value needed to reach the target sum
     */
    bool traversal(TreeNode* cur, int count) {
        // Condition: Current node is a leaf and the remaining sum is exactly 0
        if (!cur->left && !cur->right && count == 0) return true; 
        
        // Condition: Current node is a leaf but the sum does not match
        if (!cur->left && !cur->right) return false; 

        if (cur->left) { // Process Left Child
            count -= cur->left->val; // Subtract child's value from the remaining count (Move down)
            if (traversal(cur->left, count)) return true; // If path found in left subtree, return immediately
            count += cur->left->val; // Add child's value back to count (Backtrack to current state)
        }
        
        if (cur->right) { // Process Right Child
            count -= cur->right->val; // Subtract child's value from the remaining count (Move down)
            if (traversal(cur->right, count)) return true; // If path found in right subtree, return immediately
            count += cur->right->val; // Add child's value back to count (Backtrack to current state)
        }
        
        return false; // No valid path found from this node downwards
    }

public:
    bool hasPathSum(TreeNode* root, int sum) {
        if (root == NULL) return false;
        // Start the recursion by subtracting the root's value from the total sum
        return traversal(root, sum - root->val);
    }
};
