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

// 递归方法：翻转二叉树（左右子树交换）, 前序中左右
class Solution {
public:

    TreeNode* invertTree(TreeNode* root) {

        // 终止条件：如果当前节点为空，返回空指针
        if (root == NULL) return root;

        // 处理当前节点：交换左右子树
        swap(root->left, root->right);

        // 递归翻转左子树
        invertTree(root->left);

        // 递归翻转右子树
        invertTree(root->right);

        // 返回当前节点
        return root;
    }
};