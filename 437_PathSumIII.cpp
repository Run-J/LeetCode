// Solution 1: Brute Force
// For every node, start a DFS to explore all downward paths.
// Time Complexity: O(n^2)

// ------------------------------------------------------------------------


// Solution 2: Prefix Sum + Hash Map
// Time: O(n)
// Space: O(n)
//
// Core idea:
// If there exists a previous prefix sum oldSum such that:
//     curSum - oldSum = targetSum
// then the path between that previous node and current node equals targetSum.
//
// So we check:
//     oldSum = curSum - targetSum
//
// preSum[x] = number of times prefix sum x appears on current path
//
// Key points:
// 1. preSum[0] = 1 handles paths starting from root
// 2. Must store frequency (not just existence)
// 3. Backtracking is required after recursion
// 4. Use long to avoid overflow (8 bytes under LP64, e.g., LeetCode Linux).
//    On Windows (LLP64 model), long is 4 bytes, so long long should be used instead.

class Solution {

private:
    unordered_map<long, int> preSum;
    int result = 0;

    void traversal(TreeNode* root, int targetSum, long lastSum) {
        if (!root) return;

        long curSum = lastSum + root->val;
        long oldSum = curSum - targetSum;

        auto it = preSum.find(oldSum);
        if (it != preSum.end()) result += it->second;

        preSum[curSum]++;

        traversal(root->left, targetSum, curSum);
        traversal(root->right, targetSum, curSum);

        preSum[curSum]--;  // backtrack to keep path state clean
    }

public:
    int pathSum(TreeNode* root, int targetSum) {
        preSum.clear();  // clear in case the same Solution object is reused
        result = 0; // reset member variable in case the same Solution object is reused
      
        preSum[0] = 1;  // initialize base prefix sum

        traversal(root, targetSum, 0L);
        return result;
    }
};
