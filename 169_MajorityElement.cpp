// Logic:
// Assume the majority element is M.
// Since M appears more than n/2 times,
// the total count of non-M elements must be less than n/2.
// Therefore, M cannot be completely canceled out.
//
// In other words,
// if M appears 5 times and non-M appears 4 times,
// after pairwise cancellation,
// one M will remain.
//
// Time complexity: O(N)
// Space complexity: O(1)

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int candidate = 0;
        int count = 0;

        for (int num : nums) {
            if (count == 0) candidate = num;

            if (num == candidate) count++;
            else count--;
        }

        return candidate;
    }
};
