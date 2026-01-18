/*
Logic (differences vs. LeetCode 39: Combination Sum)

1) Each number in `candidates` can be used at most once in each combination (so we recurse with i + 1).
2) `candidates` may contain duplicate values, but the output must not contain duplicate combinations.

The main difficulty is (2): duplicates exist in the input, so we must de-duplicate combinations during backtracking.
This is typically done by sorting and skipping duplicates at the same recursion depth (same "tree level").
*/


// Version 1: Using a `used` array to help distinguish "same level" vs. "different level" duplicates.
class Solution {
private:
    vector<vector<int>> results;
    vector<int> path;
    int sum = 0;

    void backtracking(vector<int>& candidates, int target, int startIndex, vector<bool>& used) {
        if (sum == target) {
            results.push_back(path);
            return;
        }

        for (int i = startIndex; i < (int)candidates.size(); i++) {
            // Skip duplicates on the same tree level:
            // if the previous identical number was NOT chosen in this level, choosing current would repeat combinations.
            if (i > 0 && candidates[i] == candidates[i - 1] && used[i - 1] == false) continue;

            // Prune: candidates is sorted, so further numbers will only be larger.
            if (sum + candidates[i] > target) break;

            sum += candidates[i];
            path.push_back(candidates[i]);
            used[i] = true;

            // Move to i + 1 so each index is used at most once.
            backtracking(candidates, target, i + 1, used);

            used[i] = false;
            path.pop_back();
            sum -= candidates[i];
        }
    }

public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<bool> used(candidates.size(), false);
        sum = 0;
        path.clear();
        results.clear();

        sort(candidates.begin(), candidates.end());
        backtracking(candidates, target, 0, used);
        return results;
    }
};



// Version 2: Without `used` array (simpler for this problem).
// Sorting + "skip duplicates on the same level" is enough.
class Solution {
private:
    vector<vector<int>> results;
    vector<int> path;
    int sum = 0;

    void backtracking(vector<int>& candidates, int target, int startIndex) {
        if (sum == target) {
            results.push_back(path);
            return;
        }

        for (int i = startIndex; i < (int)candidates.size(); i++) {
            // Skip duplicates on the same tree level (same recursion depth).
            if (i > startIndex && candidates[i] == candidates[i - 1]) continue;

            // Prune: sorted array lets us stop early.
            if (sum + candidates[i] > target) break;

            sum += candidates[i];
            path.push_back(candidates[i]);

            // Use each element at most once by advancing the start index.
            backtracking(candidates, target, i + 1);

            path.pop_back();
            sum -= candidates[i];
        }
    }

public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sum = 0;
        path.clear();
        results.clear();

        sort(candidates.begin(), candidates.end());
        backtracking(candidates, target, 0);
        return results;
    }
};
