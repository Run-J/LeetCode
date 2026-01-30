// Greedy (right -> left):
// Maintain the leftmost position (goal) that can reach the last index.
// If we can move goal back to 0, then start can reach the end.
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = (int)nums.size();
        int goal = n - 1;  // leftmost index that can reach the end so far

        for (int i = n - 2; i >= 0; --i) {
            // If i can reach goal (or beyond), then i becomes the new goal
            if (i + nums[i] >= goal) {
                goal = i;
            }
        }
        return goal == 0;
    }
};


// Greedy (left -> right):
// Track the farthest index reachable so far.
// If we ever have i > farthest, the path is broken (unreachable index).
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = (int)nums.size();
        int farthest = 0;  // farthest index reachable so far

        for (int i = 0; i < n; ++i) {
            // Current position is not reachable -> cannot proceed
            if (i > farthest) return false;

            // Update farthest reach from a reachable position
            farthest = max(farthest, i + nums[i]);

            // Optional early exit: already can reach the end
            if (farthest >= n - 1) return true;
        }
        return true; // for completeness (e.g., n == 1)
    }
};
