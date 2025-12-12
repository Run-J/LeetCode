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
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 * int val;
 * TreeNode *left;
 * TreeNode *right;
 * // ... constructors ...
 * };
 */

// Solution 1: DFS / Resursion
class Solution {
public:
    /**
     * Problem: Find the Minimum Depth of a Binary Tree.
     * * Definition: The number of nodes along the shortest path from the root 
     * down to the nearest LEAF node.
     * * Strategy: Depth First Search (DFS) / Divide and Conquer.
     * * The Logic Trap: 
     * Unlike "Max Depth", we cannot simply take min(left, right) for every node.
     * If a node has only one child (e.g., Left exists, Right is NULL), the NULL side
     * returns depth 0. If we blindly take min(Left, 0), we get 0 + 1 = 1.
              1      (root)
             / \
            2   NULL
     * This incorrectly implies the current node is a leaf!
     * * We must handle "One-Legged" nodes differently than "Two-Legged" nodes.
     */
    int minDepth(TreeNode* root) {

        // 1. Base Case (Stopping Condition)
        // If the node doesn't exist, it contributes 0 to the depth.
        if (root == NULL) return 0;

        // 2. Divide (Recursive Step)
        // Ask the children: "What is the shortest path to a leaf starting from you?"
        // Note: If a child doesn't exist, this returns 0.
        int leftLength = minDepth(root->left);
        int rightLength = minDepth(root->right);

        // 3. The "Trap" Handling (One-Legged Nodes & Leaves)
        // Scenario: If one side is NULL (depth 0), it means that side is a "Dead End",
        // NOT a shortcut to a leaf. We are forced to walk down the valid path.
        // 
        // Logic:
        // - If I am a Leaf (both NULL): max(0,0) is 0. Correct.
        // - If I have only Left child (Right is NULL): max(left, 0) forces us to take Left.
        // - If I have only Right child (Left is NULL): max(0, right) forces us to take Right.
        if (root->left == NULL || root->right == NULL) {
            return 1 + max(leftLength, rightLength);
        }

        // 4. The Standard Case (Two Children)
        // Scenario: Both children exist.
        // Logic: Since both paths lead to valid leaves, we are free to choose 
        // the shorter one.
        return 1 + min(leftLength, rightLength);

    }
};


// Solution 2: BFS / Iterate
// 只有当左右孩子都为空的时候，才说明遍历的最低点了。如果其中一个孩子为空则不是最低点
class Solution {
public:
    int minDepth(TreeNode* root) {
        
        int minDepth = 0;
        if (root == NULL) return minDepth;
        queue<TreeNode*> que;
        que.push(root);

        while (!que.empty()) {
            minDepth++;
            int rowSize = que.size();

            for (int i = 0; i < rowSize; i++) {
                TreeNode* node = que.front();
                que.pop();

                if (node->left == NULL && node->right == NULL) return minDepth;
                if (node->left) que.push(node->left);
                if (node->right) que.push(node->right);
            }
        }

        return minDepth;

    }
};
