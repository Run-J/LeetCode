class Solution {
private:
    vector<vector<int>> result;
    vector<int> path;

    void backtracking(vector<int>& nums, vector<bool>& used) {
        // When the path length equals nums length,
        // we have formed a complete permutation
        if (path.size() == nums.size()) {
            result.push_back(path);
            return;
        }

        for (int i = 0; i < nums.size(); i++) {

            // -------- Tree level duplicate pruning --------
            // nums must be sorted first.
            //
            // If nums[i] == nums[i - 1] and nums[i - 1] has NOT been used
            // in the current path, it means:
            // - nums[i] and nums[i - 1] are duplicates
            // So choosing nums[i] now would generate the same permutation
            // as choosing nums[i - 1], leading to duplicate results.
            //
            // Therefore, we skip nums[i] in this case.
            if (i > 0 && nums[i] == nums[i - 1] && used[i - 1] == false)
                continue;

            // -------- Tree branch duplicate pruning --------
            // If nums[i] is already used in the current path,
            // we cannot use it again in the same permutation.
            if (used[i] == true)
                continue;


            path.push_back(nums[i]);
            used[i] = true;

            backtracking(nums, used);

            path.pop_back();
            used[i] = false;
        }
    }

public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        result.clear();
        path.clear();

        // Sorting is REQUIRED for duplicate pruning to work correctly.
        // It ensures duplicate values are adjacent.
        sort(nums.begin(), nums.end());

        vector<bool> used(nums.size(), false);
        backtracking(nums, used);

        return result;
    }
};
