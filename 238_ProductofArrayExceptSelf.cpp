
// Solution: Prefix & Postfix Products (Without Division)
//
// Idea:
// For each index i, the result is:
//   (product of all elements to the left of i)
// * (product of all elements to the right of i)
//
// We compute this in two passes:
//
// 1. Prefix pass (left to right):
//    - Use a variable `prefix` to store the product of elements before index i
//    - For each i:
//        result[i] = prefix
//        prefix *= nums[i]
//
// 2. Postfix pass (right to left):
//    - Use a variable `postfix` to store the product of elements after index i
//    - For each i:
//        result[i] *= postfix
//        postfix *= nums[i]
//
// This avoids division and correctly handles cases with zero.
//
// Time Complexity: O(n)
// Space Complexity: O(1) (excluding the output array)

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> result(n);

        // 1) Prefix pass:
        // result[i] will store the product of all elements to the LEFT of i.
        int prefix = 1;
        for (int i = 0; i < n; i++) {
            result[i] = prefix;
            prefix *= nums[i];
        }

        // 2) Postfix pass:
        // Multiply result[i] by the product of all elements to the RIGHT of i.
        int postfix = 1;
        for (int i = n - 1; i >= 0; i--) {
            result[i] *= postfix;
            postfix *= nums[i];
        }

        return result;
    }
};
