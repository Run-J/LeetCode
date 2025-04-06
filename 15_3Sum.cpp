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