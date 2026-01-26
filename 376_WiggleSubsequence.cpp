class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;

        int preDiff = 0;   
        // preDiff: the previous non-zero difference
        //  >0 means last trend was increasing
        //  <0 means last trend was decreasing
        //   0 means no trend has been established yet

        int result = 1;    
        // result: length of the longest wiggle subsequence so far
        // At least one element can always form a wiggle subsequence

        for (int i = 1; i < n; i++) {
            int curDiff = nums[i] - nums[i - 1];
            // curDiff: current difference between adjacent elements

            // If the trend changes:
            //  - from non-positive to positive (valley -> peak)
            //  - from non-negative to negative (peak -> valley)
            // then we can safely add a new element to the subsequence
            if ((curDiff > 0 && preDiff <= 0) ||
                (curDiff < 0 && preDiff >= 0)) {

                result++;      
                // A new wiggle (turning point) is confirmed

                preDiff = curDiff;  
                // Update the last trend direction
            }
        }

        return result;
    }
};
