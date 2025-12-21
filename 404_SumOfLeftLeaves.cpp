class Solution {
public:
    // Helper function for Pre-order traversal
    void traversal(TreeNode* node, int& sum) {
        // Base case: Stop recursion if node is null
        if (node == NULL) return;

        // CRITICAL LOGIC: Check if the *left child* exists and is a leaf node.
        // We identify a "left leaf" by standing at its parent.
        // 1. node->left != NULL: Ensure left child exists.
        // 2. node->left->left == NULL && node->left->right == NULL: Ensure it is a leaf.
        if (node->left != NULL && node->left->left == NULL && node->left->right == NULL) {
            sum += node->left->val;
        }

        // Recursively visit left and right subtrees to find more left leaves
        traversal(node->left, sum);
        traversal(node->right, sum);
    }

    int sumOfLeftLeaves(TreeNode* root) {
        int sum = 0;
        traversal(root, sum);
        return sum;
    }
};
