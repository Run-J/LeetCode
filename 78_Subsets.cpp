// Different from classic combination problems (e.g. LeetCode 77),
// this problem collects every node in the recursion tree,
// not only the leaf nodes.
class Solution {
private:
    vector<vector<int>> result;
    vector<int> path;

    // Backtracking function to generate all subsets
    void backtracking(vector<int>& nums, int startIndex) {
        // Every node in the recursion tree represents a valid subset
        result.push_back(path);

        // This condition is actually optional,
        // since the for-loop below already checks i < nums.size()
        if (startIndex >= nums.size()) return;

        for (int i = startIndex; i < nums.size(); i++) {
            // Choose nums[i]
            path.push_back(nums[i]);

            // Explore subsets starting from the next index
            backtracking(nums, i + 1);

            // Undo the choice (backtrack)
            path.pop_back();
        }
    }

public:
    vector<vector<int>> subsets(vector<int>& nums) {
        path.clear();
        result.clear();

        // Start backtracking from index 0
        backtracking(nums, 0);

        return result;
    }
};
