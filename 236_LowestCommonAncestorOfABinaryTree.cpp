class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        // Base case 1:
        // If current node is null, no target found in this subtree
        if (!root) return nullptr;

        // Base case 2:
        // If current node is either p or q,
        // return itself.
        // It may be:
        // 1) the LCA
        // 2) or an ancestor of the other target
        if (root == p || root == q) 
            return root;

        // Recursively search left and right subtrees
        TreeNode* leftResult = lowestCommonAncestor(root->left, p, q);
        TreeNode* rightResult = lowestCommonAncestor(root->right, p, q);

        // If both sides return non-null,
        // it means p and q are found in different subtrees.
        // Therefore, current node is their lowest common ancestor.
        if (leftResult && rightResult)
            return root;

        // Otherwise, return the non-null result (if any).
        // This means:
        // 1) both nodes are in the same subtree, or
        // 2) only one node exists in this subtree.
        return leftResult ? leftResult : rightResult;
    }
};
