
// Solution: Time complexity O(n^2)
class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        
        unordered_map<int, int> map; // Key: sum of nums1 & nums2,  Value: times of this sum appear
        int result = 0;

        for (int num1 : nums1)
        {
            for (int num2: nums2)
            {
                map[num1 + num2]++;
            }
        }

        for (int num3 : nums3)
        {
            for (int num4 : nums4)
            {
                // int target = 0 - (num3+num4);
                // if (map.find(target) != map.end())
                // {
                //     result += map[target];
                // }
                
                int target = 0 - (num3+num4); // 0-(num3+num4) = num1+num2   ==>  0 = num3+num4+num1+num2   相反数/inverse number
                auto expect = map.find(target);
                if (expect != map.end())
                {
                    result += expect->second;
                }
            }
        }

        return result;
    }
};