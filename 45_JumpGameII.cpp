// Greedy Solution
class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return 0;

        int curDistance = 0;   // farthest index reachable with current number of jumps
        int nextDistance = 0;  // farthest index reachable with one more jump
        int steps = 0;         // number of jumps used

        for (int i = 0; i < n - 1; i++) {   // last index is the target, not a launch point
            nextDistance = max(nextDistance, i + nums[i]);

            if (i == curDistance) {         // current level fully scanned
                steps++;    // into next range / next jump
                curDistance = nextDistance;
                if (curDistance >= n - 1) break;
            }
        }
        return steps;
    }
};
