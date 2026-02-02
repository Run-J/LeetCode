class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        // Use unordered_set to remove duplicates and allow O(1) average lookup
        unordered_set<int> s(nums.begin(), nums.end());

        int result = 0;

        // Iterate through the set (already deduplicated)
        for (int num : s) {

            // Only start counting when num is the beginning of a sequence
            // i.e., (num - 1) does NOT exist in the set
            if (s.count(num - 1)) continue;

            int cur = num;
            int len = 1;

            // Count the length of the consecutive sequence starting from num
            while (s.count(cur + 1)) {
                cur++;
                len++;
            }

            // Update the maximum length found so far
            result = max(result, len);
        }

        return result;
    }
};
