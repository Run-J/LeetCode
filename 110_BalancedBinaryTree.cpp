// Logic Strategy: Bottom-Up Recursion (Post-order Traversal)
// ---------------------------------------------------------
// Instead of calculating the height of every node repeatedly (which would be O(N^2)),
// we return the height directly up the chain.
//
// Key Trick: The "Signal Flag" (-1)
// We need to return two pieces of info: the Height (int) and the Balance Status (bool).
// Since we can only return one int, we use -1 as a special error code.
//
// 1. If a node is Balanced: Return its actual Height (>= 0).
// 2. If a node is Unbalanced: Return -1.
// 3. Propagation: If a child returns -1, the parent immediately catches it 
//    and also returns -1, bubbling the "error" all the way to the top.
class Solution {
public:
    int getHight(TreeNode* node) {
        // 1. Base Case: An empty node is balanced and has height 0.
        if (node == NULL) return 0;

        // 2. Recursive Step (Left)
        int leftHight = getHight(node->left);
        // Optimization: Fail Fast.
        // If the left subtree reported an imbalance (-1), we stop immediately.
        // There is no need to calculate the right side.
        if (leftHight == -1) return -1;

        // 3. Recursive Step (Right)
        int rightHight = getHight(node->right);
        // Optimization: Fail Fast.
        // If the right subtree is unbalanced, bubble the -1 up.
        if (rightHight == -1) return -1;

        // 4. The Balance Check (The Core Logic)
        // If the height difference between left and right is > 1, 
        // this specific node breaks the balance rule. Return -1.
        // Note: abs() calculates absolute difference (e.g., abs(2-4) = 2).
        if (abs(leftHight - rightHight) > 1) return -1;

        // 5. Success Case
        // If we passed the check, we return our own actual height to the parent.
        // Height = 1 (myself) + the taller of my two children.
        return 1 + max(leftHight, rightHight);
    }

    bool isBalanced(TreeNode* root) {
        // If getHight returns -1, it means an imbalance was found somewhere.
        // If it returns any other number (0, 1, 2...), the tree is balanced.
        return getHight(root) != -1;
    }
};
