// Utilizing the properties of a BST: an in-order traversal will yield an increasing sequence (identical values ​​will appear consecutively).
class Solution {

private:
    TreeNode* pre = NULL;      // Pointer to the previously visited node in inorder traversal
    int counter = 0;           // Count of the current value's consecutive occurrences
    int maxCounter = 0;        // Maximum frequency encountered so far
    vector<int> result;        // Stores all mode values (may contain multiple modes)

public:
    void traversal(TreeNode* cur) {
        // Base case: empty node
        if (cur == NULL) return;

        // Step 1: Inorder traversal - visit left subtree
        traversal(cur->left);

        // Step 2: Process current node
        if (pre == NULL) {
            // First node visited in inorder traversal
            counter = 1;
        } else if (cur->val == pre->val) {
            // Current value is the same as previous value
            // Increment consecutive count
            counter++;
        } else {
            // Current value is different from previous value
            // Reset consecutive count
            counter = 1;
        }

        // Step 3: Update previous node pointer
        pre = cur;

        // Step 4: Update result based on current frequency
        if (counter == maxCounter) {
            // Current value has the same maximum frequency (another mode)
            result.push_back(cur->val);
        } else if (counter > maxCounter) {
            // Found a higher frequency
            // Update max frequency and reset result list
            maxCounter = counter;
            result.clear();
            result.push_back(cur->val);
        }

        // Step 5: Inorder traversal - visit right subtree
        traversal(cur->right);
    }

    vector<int> findMode(TreeNode* root) {
        // Perform inorder traversal to find all modes
        traversal(root);
        return result;
    }
};
