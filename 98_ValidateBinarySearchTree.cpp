// Logic:
// I use the fact that the inorder traversal of a BST is strictly increasing, track the previous node with pre, and return false if the current value is not greater than the previous one.
//
// Traverse the binary tree using inorder traversal (left → root → right)
// For a Binary Search Tree (BST), the inorder traversal result must be strictly increasing
// Use pre to record the previously visited node during inorder traversal
// When visiting the current node, compare its value with the value of pre
// If the current value is less than or equal to the previous value, the BST property is violated
// After processing the current node, update pre to the current node
class Solution {
private:
    TreeNode* pre = NULL;

public:
    bool isValidBST(TreeNode* root) { 
        if (root == NULL) return true;

        bool left = isValidBST(root->left); // left

        if (pre != NULL && root->val <= pre->val) return false; // root
        pre = root;

        bool right = isValidBST(root->right); // right

        return left && right;
    }
};
