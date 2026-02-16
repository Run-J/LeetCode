// Solution 1 (Optimal):
// Idea:
// Target order after flatten is preorder: root -> left -> right.
//
// We traverse in the reverse of preorder: right -> left -> root.
// Use a pointer `prev` to record the head of the already-flattened list.
// For each node:
//   1. Connect current node's right to prev.
//   2. Set left to nullptr (as the question description required).
//   3. Move prev to current node.
//
// Since each node is processed exactly once,
// Time Complexity: O(n)
// Space Complexity: O(h) (recursion stack, h = tree height)

class Solution {
private:
    TreeNode* prev = nullptr;

public:
    void flatten(TreeNode* root) {
        if (!root) return;

        flatten(root->right);  // reverse preorder
        flatten(root->left);

        root->right = prev;    // connect to already flattened list
        root->left = nullptr;  // must set left to null
        prev = root;           // move head pointer
    }
};



// Solution 2:
// Postorder-style reconstruction (left -> right -> root)
//
// Idea:
// 1. Recursively flatten left subtree.
// 2. Recursively flatten right subtree.
// 3. At current root:
//    - Save original right subtree.
//    - Move flattened left subtree to right.
//    - Set left to nullptr.
//    - Find the tail of the new right chain.
//    - Append the original right subtree to the tail.
//
// Time Complexity:
// Worst case (e.g., all nodes on the left):
// Each level scans the entire flattened left chain.
// Total operations: 1 + 2 + ... + (n-1) = n^2/2 = Θ(n²)
//
// Space Complexity: O(h) recursion stack

class Solution {
public:
    void flatten(TreeNode* root) {
        if (!root) return;

        flatten(root->left);
        flatten(root->right);

        TreeNode* rightTemp = root->right;

        if (root->left) {
            root->right = root->left;
            root->left = nullptr;

            // Use a separate pointer to avoid modifying root itself
            TreeNode* cur = root;
            while (cur->right) {
                cur = cur->right;
            }

            cur->right = rightTemp;
        }
    }
};
