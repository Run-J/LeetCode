// Logic 1:
// Brute Force
// Enumerate all possible subarrays and calculate their sums.
// For each starting index i, iterate to the end and accumulate the sum.
// If the accumulated sum equals k, increment result.
// Time Complexity: O(N^2)
// Space Complexity: O(1)


// Logic 2:
// Prefix Sum + Hash Map (Optimal Solution)
//
// Key idea:
//
// Why store frequency instead of just existence?
// Because the same prefix sum may appear multiple times.
// **Each occurrence represents a different valid subarray**.
//
// Example:
// nums = [1, -1, 1, 1, 1, 1], k = 3
// When a prefixSum value repeats, multiple valid subarrays can end at current index.
//
// Important initialization:
// prefixCount[0] = 1
// This handles the case where a subarray starting from index 0 sums to k.
//
// Time Complexity: O(N)
//   Each element is processed once.
// Space Complexity: O(N)
//   In worst case, all prefix sums are different.
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> prefixCount;
        prefixCount[0] = 1; // initialize the prefix sum 0 is 1
        int result = 0;
        int prefixSum = 0;

        for (int num : nums) {
            prefixSum += num;
            if ( prefixCount.count(prefixSum - k) ) { // prefixSum - valueWantFound = k
                result += prefixCount[prefixSum-k];
            }
            prefixCount[prefixSum]++;
        }

        return result;
    }
};
