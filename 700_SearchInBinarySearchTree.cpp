// Solution 1: Recursion
// Since this is a binary search tree, we can leverage the BST property.
class Solution {
public:
    TreeNode* searchBST(TreeNode* root, int val) {
        
        if (root == NULL || root->val == val) return root;

        TreeNode* result = NULL;
        if (val < root->val) result = searchBST(root->left, val);
        if (val > root->val) result = searchBST(root->right, val);

        return result;
    }
};


// Solution 2: Iterative
class Solution {
public:
    TreeNode* searchBST(TreeNode* root, int val) {

        while (root != NULL) {
            if (val < root->val) root = root->left;
            else if (val > root->val) root = root->right;
            else return root;
        }
        return NULL;
    }
};
