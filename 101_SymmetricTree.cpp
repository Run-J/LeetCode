// LeetCode 101: Symmetric Tree
// Approach:
// The goal is to determine whether a binary tree is symmetric around its center.
// I use a recursive helper function to compare the left and right subtrees in a mirrored fashion.
// This is essentially a "mirrored preorder traversal": check root value → outer pair → inner pair.
// At each step, we ensure the values are equal and that the structure mirrors.
// Traversal order: Root → Outside (left->left vs right->right) → Inside (left->right vs right->left)

/**
 * Definition for a binary tree node.
 */
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:

    // Helper function to compare two subtrees in mirror order
    bool compare(TreeNode* left, TreeNode* right) {

        // Case 1: One subtree is null and the other is not — not symmetric
        if (!left && right) return false;
        if (left && !right) return false;

        // Case 2: Both are null — symmetric
        if (!left && !right) return true;

        // Case 3: Values do not match — not symmetric
        if (left->val != right->val) return false;

        // Recursive comparison:
        //  - Outside pair: left->left vs right->right
        //  - Inside pair: left->right vs right->left
        bool outside = compare(left->left, right->right);
        bool inside = compare(left->right, right->left);

        return outside && inside;
    }

    // Main function: checks if the tree is symmetric
    bool isSymmetric(TreeNode* root) {

        if (!root) return true; // An empty tree is symmetric
        
        return compare(root->left, root->right);
    }
};
