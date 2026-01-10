// This problem is partially similar in approach to LeetCode 106.
class Solution {
public:

    // Keep the left-closed, right-open interval [)
    TreeNode* buildTree(vector<int>& nums, int left, int right) {
        if (left >= right) return NULL;

        int maxValueIndex = left;
        for (int i = left + 1; i < right; i++) {
            if (nums[i] > nums[maxValueIndex]) maxValueIndex = i;
        }

        TreeNode* root = new TreeNode(nums[maxValueIndex]);

        root->left = buildTree(nums, left, maxValueIndex);
        root->right = buildTree(nums, maxValueIndex + 1, right);

        return root;
    }

    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        return buildTree(nums, 0, nums.size()); 
    }
};
