// Solution 1: Greedy Algorithm
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int result = INT_MIN;
        int count = 0;

        for (int i = 0; i < nums.size(); i++) {
            count += nums[i];
            if (count > result) result = count;

            // Key idea:
            // If the current sum becomes negative, it will only reduce
            // the sum of any subarray that includes it in the future.
            // Therefore, we reset the current sum and start fresh.
            if (count < 0) count = 0;
        }

        return result;
    }
};
