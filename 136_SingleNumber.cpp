// Logic:
// Use XOR.
// If a number appears twice, its bits will cancel out (a ^ a = 0).
// If a number appears once, its bits will remain in the final result.
// 
// Example: [2, 2, 1]
//
//   0 0 1 0   (2)
// ^ 0 0 1 0   (2)
// ^ 0 0 0 1   (1)
// ------------
//   0 0 0 1   => result = 1
//
//
// Time Complexity: O(N)  (Linear time)
// Space Complexity: O(1) (Constant extra space)

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int result = 0;

        for (int num : nums) {
            result ^= num;
        }

        return result;
    }
};
