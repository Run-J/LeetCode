// Similar to LeetCode 77, except for the pruning logic
class Solution {

private:
    vector<vector<int>> results;
    vector<int> path;
    int sum = 0;

    void backtracking(int k, int n, int startIndex) {
        // If we've chosen k numbers, we must stop
        if (path.size() == k) {
            if (sum == n) results.push_back(path);
            return;
        }

        for (int i = startIndex; i <= 9 ; i++) {
            // Strong prune: since i only increases, if this is too big, later will be too big too
            if (sum + i > n) break;

            sum += i;
            path.push_back(i);
            backtracking(k, n, i+1);

            sum -= i;
            path.pop_back();
        }
    }

public:
    vector<vector<int>> combinationSum3(int k, int n) {
        backtracking(k, n, 1);
        return results;
    }
};
