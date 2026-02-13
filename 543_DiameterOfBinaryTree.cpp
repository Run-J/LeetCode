// Logic:
// The diameter at a node = left subtree depth + right subtree depth (measured in edges).

// Important:
// We must treat EVERY node as a potential "highest point" of the diameter.
// If we only calculate the diameter at the root, we may miss the longest path,
// because the longest path might exist entirely inside a subtree.

// Approach:
// 1. Use postorder traversal (DFS).
// 2. For each node:
//    - Recursively compute the maximum depth of its left subtree.
//    - Recursively compute the maximum depth of its right subtree.
//    - Update the global diameter using:
//          leftDepth + rightDepth
//    - Return the maximum depth of the current subtree:
//          max(leftDepth, rightDepth) + 1
         

// Time Complexity: O(n)
// Each node is visited exactly once.

// Space Complexity: O(h)
// Recursive call stack, where h is the height of the tree.


class Solution {
private: 
    int result = 0;  // Stores the maximum diameter (measured in edges)

public:
    int maximumDepth(TreeNode* root) {
        if (!root) return 0;

        int leftDepth = maximumDepth(root->left);
        int rightDepth = maximumDepth(root->right);

        // Update the diameter: the longest path passing through the current node 
        // = left subtree depth + right subtree depth (measured in edges).
        result = max(result, leftDepth + rightDepth);

        // Return the maximum depth of the current node (measured in number of nodes).
        return max(leftDepth, rightDepth) + 1;
    }

    int diameterOfBinaryTree(TreeNode* root) {
        maximumDepth(root);
        return result;
    }
};
