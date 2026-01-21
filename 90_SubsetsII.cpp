// Reference: LeetCode 78 (Subsets) and LeetCode 90 (Subsets II)
// Key ideas:
// 1. Collect nodes instead of only leaf nodes in the recursion tree
// 2. Duplicates are not allowed at the same recursion level,
//    but are allowed along the same recursion path
class Solution {
private:
    vector<vector<int>> result;
    vector<int> path;


    void backtracking(vector<int>& nums, int startIndex) {
        // Every recursion node represents a valid subset
        result.push_back(path);

        // if (startIndex > nums.size()) return;  // This condition is unnecessary because the for-loop already ensures i < nums.size()

        for (int i = startIndex; i < nums.size(); i++) {
            // Skip duplicate numbers at the same recursion level
            if (i > startIndex && nums[i] == nums[i - 1]) {
                continue;
            }
          
            path.push_back(nums[i]);
            backtracking(nums, i + 1);
            path.pop_back();
        }
    }

public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        path.clear();
        result.clear();

        // DON'T forget to sort the array to make duplicate detection possible
        sort(nums.begin(), nums.end());

        backtracking(nums, 0);
        return result;
    }
};
