// Logic:
// 1: Use backtracking (DFS) to build combinations
// At each step, we choose one number and go deeper until the current combination has k numbers.

// 2: Use startIndex to avoid duplicates
// Each recursive call only considers numbers after the current one (i + 1), ensuring combinations are in increasing order.

// 3: Prune the search space
// If the remaining available numbers are fewer than what we still need, stop early to avoid useless recursion.

class Solution {

private:
    vector<vector<int>> results;  // store all valid combinations
    vector<int> path;             // current combination (path)

    void backtracking(int n, int k, int startIndex) {

        // If we have selected k numbers, record the result
        if (path.size() == k) {
            results.push_back(path);
            return;
        }

        /*
         * Pruning:
         * - still need (k - path.size()) numbers
         * - remaining available numbers: n - i + 1
         * - if remaining < needed, no valid combination is possible
         */
        for (int i = startIndex; i <= n - (k - path.size()) + 1; i++) {

            path.push_back(i);            // choose current number
            backtracking(n, k, i + 1);    // move to next number (DFS)
            path.pop_back();              // backtrack
        }
    }

public:
    vector<vector<int>> combine(int n, int k) {
        backtracking(n, k, 1);  // start from number 1
        return results;
    }
};
