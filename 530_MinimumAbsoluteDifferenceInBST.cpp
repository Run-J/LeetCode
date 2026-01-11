// Using the fact that the inorder traversal of a BST is increasing, we track the previous node with pre and compute the difference between adjacent nodes to find the minimum.
class Solution {
private:
    TreeNode* pre = NULL;
    int minValue = INT_MAX;

public:
    void traversal(TreeNode* cur) {
        if (cur == NULL) return;

        traversal(cur->left);
        if (pre != NULL && cur->val - pre->val < minValue) minValue = cur->val - pre->val;
        pre = cur;
        traversal(cur->right);
    }

    int getMinimumDifference(TreeNode* root) {
        traversal(root);
        return minValue;
    }
};
