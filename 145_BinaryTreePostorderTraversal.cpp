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
class Solution {
public:

    void traversal(TreeNode* cur, vector<int>& result) {
        if (!cur) return;

        traversal(cur->left, result);
        traversal(cur->right, result);
        result.push_back(cur->val);
    }

    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> result;
        traversal(root, result);
        return result;
    }
};


// 非recursion写法，用stack
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        
        stack<TreeNode*> st;
        vector<int> result;

        if (root == nullptr) return result;

        st.push(root);
        while (!st.empty()) {
            TreeNode* node = st.top();
            st.pop();

            if (node != nullptr) result.push_back(node->val);
            else continue;

            st.push(node->left);
            st.push(node->right);
        }

        reverse(result.begin(), result.end());
        return result;
    }
};