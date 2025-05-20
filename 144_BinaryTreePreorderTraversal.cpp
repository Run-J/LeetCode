/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     // 默认构造函数：初始化为 0 值叶节点
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     // 单参数构造函数：只设置当前值
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     // 三参数构造函数：设置值和左右孩子
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

// 写递归的思路：
// 1: 确定递归函数的参数和返回值
// 2：确定终止条件
// 3: 确定单层递归的逻辑
class Solution {
public:

    // 辅助函数：递归实现前序遍历（中 → 左 → 右）
    void traversal(TreeNode* cur, vector<int>& result) {

        // 空节点直接返回（递归终止条件）
        if (cur == nullptr) return;

        // 前序遍历第一步：先访问根节点
        result.push_back(cur->val);

        // 递归遍历左子树
        traversal(cur->left, result);

        // 递归遍历右子树
        traversal(cur->right, result);
    }

    // 主函数：调用递归函数并返回遍历结果
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> result;
        traversal(root, result);
        return result;
    }

};