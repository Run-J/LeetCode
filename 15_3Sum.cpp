
// 用双指针法
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result;
        sort(nums.begin(), nums.end()); // 先排序

        for (int i = 0; i < nums.size(); i++)
        {
            // 排序之后如果第一个元素已经大于零，那么无论如何组合都不可能凑成三元组，直接返回结果就可以了
            if (nums[i] > 0)
            {
                return result;
            }

            // 正确去重a方法
            if ( i > 0 && nums[i] == nums[i - 1])
            {
                continue;
            }

            int left = i+1;
            int right = nums.size() - 1;
            while (right > left)
            {
                if (nums[i] + nums[left] + nums[right] > 0) right--;
                else if (nums[i] + nums[left] + nums[right] < 0) left++;
                else {
                    
                    result.push_back( vector<int>{nums[i], nums[left], nums[right]} );

                    // 去重b,c
                    while (right > left && nums[right] == nums[right-1]) right--;
                    while (right > left && nums[left] == nums[left+1]) left++;

                    right--;
                    left++;
                }
            }
        }

        return result;

    }
};


// 模仿 2SUM 的解题方法，用哈希set储存遍历过的元素
using namespace std;

// 在一个数组中找到所有和为 0 的不重复三元组（a + b + c = 0）
// 三元组中不能使用相同下标，且不能有重复的组合（例如 [1,2,-3] 和 [2,1,-3] 视为同一组）
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result;

        // 先对数组排序，为了后续去重 & 使用双指针/哈希
        sort(nums.begin(), nums.end());

        // 外层循环：固定第一个数 a = nums[i]
        for (int i = 0; i < nums.size(); i++) {
            // 剪枝优化1：若 a > 0，后续数也都 > 0，不可能满足 a + b + c = 0
            if (nums[i] > 0)
                break;

            // 剪枝优化2：若当前 a 与前一个 a 相同，跳过，避免重复三元组
            if (i > 0 && nums[i] == nums[i - 1])
                continue;

            // 用 unordered_set 存储已经遍历过的 b 值，用于检索目标 b = -(a + c)
            unordered_set<int> seen;

            // 内层循环：遍历 a 后面的所有数，当前 nums[j] 视为 c
            for (int j = i + 1; j < nums.size(); j++) {
                // 计算当前需要的 b，使得 a + b + c == 0
                int target = -nums[i] - nums[j];

                // 如果之前出现过这个 b（即 seen 中有 target），就说明找到了一个满足条件的三元组
                if (seen.count(target)) {
                    result.push_back({nums[i], target, nums[j]});

                    // 跳过重复的 c（nums[j]）避免相同三元组重复加入结果
                    while (j + 1 < nums.size() && nums[j] == nums[j + 1])
                        j++;
                }

                // 把当前 nums[j] 存入 seen，为后续匹配做准备（作为 b 值被后面新的 c 使用）
                seen.insert(nums[j]);
            }
        }

        return result;
    }
};
