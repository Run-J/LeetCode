

// Use hash map (unordered_map), key is element, and the value is index of element
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        
        unordered_map<int, int> numsIndex;

        for (int i = 0; i < nums.size(); i++)
        {
            int expect = target - nums[i];
            auto iterator = numsIndex.find(expect);
            if ( iterator != numsIndex.end() )
            {
                return {i, iterator->second};
            }

            numsIndex.insert(pair<int, int>(nums[i], i));

        }

        return {};

    }
};