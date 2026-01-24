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

      
        // Try to place each unused element at the current position
        for (int i = 0; i < nums.size(); i++) {

            // Skip elements that have already been used
            if (used[i]) continue;

            used[i] = true;
            path.push_back(nums[i]);

            backtracking(nums, used);
          
            path.pop_back();
            used[i] = false;
        }
    }

public:
    vector<vector<int>> permute(vector<int>& nums) {
        result.clear();
        path.clear();

        // used array tracks which indices are already used
        vector<bool> used(nums.size(), false);

        // Start backtracking
        backtracking(nums, used);

        return result;
    }
};
