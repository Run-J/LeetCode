// Key Idea:
// Use the sliding window technique to find the smallest subarray
// whose sum is greater than or equal to the target.
// Expand the window by moving the right pointer,
// and shrink it from the left side while the sum remains >= target.
// During each valid window, update the minimum length.


class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        

        int result = INT32_MAX;
        int sum = 0;
        int left = 0;

        for (int right = 0; right < nums.size(); right++)
        {
            sum += nums[right];
            while (sum >= target)
            {
                int subLength = right - left + 1;
                result = result < subLength ? result : subLength;

                sum -= nums[left];
                left++;
            }
        }

        return result == INT32_MAX ? 0 : result;
    }
};

// 核心思路：
// 使用滑动窗口法寻找最短的连续子数组，
// 使其和大于等于给定的 target。
// 右指针不断向右扩展窗口，
// 当窗口内的 sum 满足 ≥ target 时，
// 尝试通过左指针缩小窗口，并更新最小子数组长度。
