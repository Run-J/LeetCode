class Solution {
private:

    vector<vector<int>> result;
    vector<int> path;


    void backtracking(vector<int>& nums, int startIndex) {

        // The problem requires subsequences of length >= 2
        // Any path with size > 1 is a valid answer
        if (path.size() > 1) {
            result.push_back(path);
        }

        /**
         * used array for "same-level" deduplication
         *
         * Meaning:
         *   used[x] == 1 indicates that the value (x - 100)
         *   has already been used at the current recursion level.
         *
         * Why size 201?
         *   Constraints: -100 <= nums[i] <= 100
         *   We map values to indices by adding an offset of 100.
         *
         * Important:
         *   - used is a LOCAL variable
         *   - It is recreated and reset for each recursion level
         *   - It is only used for same-level deduplication
         *   - Therefore, it does NOT need to be backtracked
         */
        int used[201] = {0};


        for (int i = startIndex; i < nums.size(); i++) {

            /**
             * Pruning and deduplication:
             *
             * 1) Non-decreasing constraint:
             *    If the path is not empty, the current number must be
             *    >= the last element in path.
             *
             * 2) Same-level deduplication:
             *    If this value has already been used at the current level,
             *    choosing it again would generate duplicate subsequences.
             */
            if ((!path.empty() && nums[i] < path.back()) ||
                used[nums[i] + 100] != 0) {
                continue;
            }


            path.push_back(nums[i]);
            // Mark this value as used at the current recursion level
            used[nums[i] + 100] = 1;
            backtracking(nums, i + 1);
            path.pop_back();
        }
    }

public:
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        // Clear state to avoid data pollution across calls
        result.clear();
        path.clear();

        backtracking(nums, 0);

        return result;
    }
};
