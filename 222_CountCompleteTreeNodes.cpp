// Solution 1: Standard Recursion (Time: O(N))
// Logic: Traverse every node using Post-order traversal.
class Solution {
public:
    int countNodes(TreeNode* root) {
        // Base case: If the node is empty, it contributes 0 to the count.
        if (root == NULL) return 0;

        // Recursive step: Count nodes in left and right subtrees.
        int left = countNodes(root->left);
        int right = countNodes(root->right);

        // Aggregate: Total = Left count + Right count + 1 (current node itself).
        return left + right + 1;
    }
};


// Solution 2: Optimized for Complete Binary Trees (Time: O(log N * log N))
// Logic: If a subtree is a "Perfect Binary Tree" (left depth == right depth), 
// we calculate nodes using math formula instead of traversal.
class Solution {
public:
    int countNodes(TreeNode* root) {
        if (root == NULL) return 0;

        TreeNode* left = root->left;
        TreeNode* right = root->right;

        // Initialize depths to 0 (Fix: ensured both are initialized)
        int leftDepth = 0, rightDepth = 0; 
        
        // Measure the depth of the leftmost edge
        while (left != NULL) {
            left = left->left;
            leftDepth++;
        }
        
        // Measure the depth of the rightmost edge
        while (right != NULL) {
            right = right->right;
            rightDepth++;
        }

        // Optimization: Check if the subtree is "Perfect"
        // If left depth equals right depth, this subtree is full.
        // We use the formula: (2^h) - 1
        // we started counting depth from children, not root.
        if (leftDepth == rightDepth) {
            return (2 << leftDepth) - 1; 
        }

        // Fallback: If not perfect, recursively count normally
        int leftSum = countNodes(root->left);
        int rightSum = countNodes(root->right);
        
        return leftSum + rightSum + 1;
    }
};
