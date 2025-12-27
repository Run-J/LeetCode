// Solution 1: Use index ranges
// Logic: the same as LeetCode 106 (Construct Binary Tree from Inorder and Postorder Traversal)
class Solution {
public:

    // Build a subtree using preorder[preorderBegin, preorderEnd)
    // and inorder[inorderBegin, inorderEnd)
    // Interval convention: [begin, end)
    TreeNode* traversal(vector<int>& inorder, int inorderBegin, int inorderEnd,
                        vector<int>& preorder, int preorderBegin, int preorderEnd) {
        // Base case: empty subtree
        if (preorderBegin == preorderEnd) return NULL;

        // The first element in preorder is the root of the current subtree
        int rootVal = preorder[preorderBegin];
        TreeNode* root = new TreeNode(rootVal);

        // Base case: single-node subtree
        if (preorderEnd - preorderBegin == 1) return root;

        // Find the root position in inorder within [inorderBegin, inorderEnd)
        int delimiterIndex = inorderBegin;
        for (; delimiterIndex < inorderEnd; delimiterIndex++) {
            if (inorder[delimiterIndex] == root->val) break;
        }

        // Split inorder into left and right subtrees
        int leftInorderBegin = inorderBegin;
        int leftInorderEnd   = delimiterIndex;

        int rightInorderBegin = delimiterIndex + 1;
        int rightInorderEnd   = inorderEnd;

        // Number of nodes in the left subtree
        int leftSize = delimiterIndex - inorderBegin;

        // Split preorder according to the size of the left subtree
        int leftPreorderBegin = preorderBegin + 1;
        int leftPreorderEnd   = leftPreorderBegin + leftSize;

        int rightPreorderBegin = leftPreorderEnd;
        int rightPreorderEnd   = preorderEnd;

        // Recursively build left and right subtrees
        root->left  = traversal(inorder, leftInorderBegin, leftInorderEnd,
                                 preorder, leftPreorderBegin, leftPreorderEnd);
        root->right = traversal(inorder, rightInorderBegin, rightInorderEnd,
                                 preorder, rightPreorderBegin, rightPreorderEnd);

        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        // Edge case: empty input
        if (inorder.empty() || preorder.empty()) return NULL;

        // Carefully follow the [begin, end) interval convention
        return traversal(inorder, 0, inorder.size(), preorder, 0, preorder.size());
    }
};




// Solution 2: Easier to understand but slower, since it creates many vectors
// Logic: the same as LeetCode 106 (Construct Binary Tree from Inorder and Postorder Traversal)
class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {

        // Step 1
        if (preorder.size() == 0) return NULL; // empty tree

        TreeNode* root = new TreeNode(preorder[0]); // the first element in preorder is the root

        if (preorder.size() == 1) return root; // the tree has only one node (the root)

        // Step 2
        int index = 0;
        for (int i = 0; i < inorder.size(); i++) {
            if (inorder[i] == root->val) { // find the index of the root in the inorder vector
                index = i;
                break;
            }
        }

        // Step 3
        vector<int> leftTreeInorder(inorder.begin(), inorder.begin() + index);
        vector<int> rightTreeInorder(inorder.begin() + index + 1, inorder.end());

        vector<int> leftTreePreorder(preorder.begin() + 1, 
                                    preorder.begin() + 1 + leftTreeInorder.size());
        vector<int> rightTreePreorder(preorder.begin() + 1 + leftTreeInorder.size(), 
                                    preorder.end());

        
        // Step 4
        root->left = buildTree(leftTreePreorder, leftTreeInorder);
        root->right = buildTree(rightTreePreorder, rightTreeInorder);

        return root;

    }
};
