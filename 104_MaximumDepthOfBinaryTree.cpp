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


// Solution 1 (Depth First Search (DFS) / Recursion (Post-order):
// Don't try to look at the whole tree at once. Instead, think recursively.
// The Logic: If you are a node (say, the Root), how do you know the total depth?
//     Ask your Left Child: "What is the max depth down your path?"
//     Ask your Right Child: "What is the max depth down your path?"
//     Take the bigger of those two numbers, and add 1 (for yourself).
class Solution {
public:
    int maxDepth(TreeNode* root) {
        if (root == NULL) return 0;

        int leftDepth = maxDepth(root->left);
        int rightDepth = maxDepth(root->right);

        return 1 + max(leftDepth, rightDepth);
    }
};




// Solution 2 (Breadth First Search (BFS) / Iterative):
// 用队列辅助层序遍历，记录层数
class Solution {
public:
    int maxDepth(TreeNode* root) {
        
        int maxDepth = 0;
        if (root == NULL) return maxDepth; // maxDepth is 0
        queue<TreeNode*> que;
        que.push(root);

        while (!que.empty()) {
            maxDepth++;
            int rowSize = que.size();

            for (int i = 0; i < rowSize; i++) {
                TreeNode* node = que.front();
                que.pop();

                if (node->left) que.push(node->left);
                if (node->right) que.push(node->right);
            }
        }

        return maxDepth;
    }
};
