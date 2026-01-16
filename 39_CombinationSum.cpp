// Logic: Similar to LC77 and LC216. 
// Key difference: Each number can be used multiple times, so 'startIndex' stays at 'i' in recursion.
class Solution {
private:
    vector<vector<int>> results;
    vector<int> path;
    int sum = 0;

    void backtracking(vector<int>& candidates, int target, int startIndex) {
        // Base case: target reached
        if (sum == target) {
            results.push_back(path);
            return;
        }
        
        // Pruning: By sorting the candidates, we can stop early if sum + candidates[i] exceeds target.
        // This eliminates the need for an explicit "if (sum > target)" check at the start of the function.
        for (int i = startIndex; i < candidates.size() && sum + candidates[i] <= target; i++) {
            sum += candidates[i];
            path.push_back(candidates[i]);

            // Note: Pass 'i' instead of 'i + 1' to allow reusing the same element.
            backtracking(candidates, target, i);
            
            // Backtrack: restore state
            sum -= candidates[i];
            path.pop_back();
        }
    }

public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        results.clear();
        path.clear();
        sum = 0;
        
        // Sorting is mandatory for the pruning logic (sum + candidates[i] <= target) to work.
        sort(candidates.begin(), candidates.end()); 

        backtracking(candidates, target, 0);
        return results;
    }
};
