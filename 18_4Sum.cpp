class Solution {
public:
    // 找出数组中所有不重复的四元组，使其和为 target
    // 要求下标不重复，四元组不能重复
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> result;

        // 排序是关键：方便双指针、去重、剪枝
        sort(nums.begin(), nums.end());

        // 第一个数 a 的遍历
        for (int i = 0; i < nums.size(); i++) {
            // 剪枝：如果 a 已经比 target 大且 target 非负，后续不可能满足
            if (nums[i] > target && (target >= 0 || nums[i] >= 0)) break;

            // 跳过重复 a
            if (i > 0 && nums[i] == nums[i - 1]) continue;

            // 第二个数 b 的遍历
            for (int j = i + 1; j < nums.size(); j++) {
                // 剪枝：a + b 已经超过 target，且 target 为非负，无需继续
                if (nums[i] + nums[j] > target && (target >= 0 || nums[i] + nums[j] >= 0)) break;

                // 跳过重复 b
                if (j > i + 1 && nums[j] == nums[j - 1]) continue;

                // 双指针寻找 c 和 d，使 a + b + c + d == target
                int left = j + 1;
                int right = nums.size() - 1;

                while (left < right) {
                    // 使用 long long 避免整数溢出
                    long long sum = (long long)nums[i] + nums[j] + nums[left] + nums[right];

                    if (sum > target) {
                        right--;  // 总和过大，右指针左移
                    } else if (sum < target) {
                        left++;   // 总和过小，左指针右移
                    } else {
                        // 找到一组合法四元组
                        result.push_back({nums[i], nums[j], nums[left], nums[right]});

                        // 跳过重复 c（nums[left]）
                        while (left < right && nums[left] == nums[left + 1]) left++;
                        // 跳过重复 d（nums[right]）
                        while (left < right && nums[right] == nums[right - 1]) right--;

                        // 移动指针寻找下一组解
                        left++;
                        right--;
                    }
                }
            }
        }

        return result;
    }
};
