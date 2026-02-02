// LeetCode 283 - Move Zeroes
// 
// Approach:
// Two pointers (slow & fast).
// 1. Traverse the array using `fast`.
//    - Copy all non-zero elements to the front of the array
//    - Maintain their original relative order
// 2. After traversal, fill the remaining positions with zeros.
//
// Time Complexity: O(n)
// Space Complexity: O(1) (in-place)

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int slow = 0; // Index to write the next non-zero element
        int fast = 0; // Index to traverse the array

        // First pass:
        // Move all non-zero elements to the front
        while (fast < nums.size()) {
            if (nums[fast] != 0) {
                nums[slow] = nums[fast];
                slow++;
            }
            fast++;
        }

        // Second pass:
        // Fill the remaining positions with zeros
        while (slow < nums.size()) {
            nums[slow] = 0;
            slow++;
        }
    }
};
