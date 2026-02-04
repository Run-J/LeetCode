// Solution 1:
// Time Complexity: O(N)
// Space Complexity: O(1)
class Solution {
public:
    void sortColors(vector<int>& nums) {

        /*
         Invariant maintained by the algorithm
         (must hold at the beginning of every while iteration):

         [0 .. i-1]     all 0s   (finished 0 region)
         [i .. j-1]     all 1s   (finished 1 region)
         [j .. k]       unknown  (currently scanning / unclassified)
         [k+1 .. n-1]   all 2s   (finished 2 region)

         Pointer meanings:
         i : the next position where a 0 should be placed
         j : the current position being examined
         k : the next position where a 2 should be placed
        */

        int i = 0;
        int j = 0;
        int k = nums.size() - 1;

        // Continue as long as there is an unclassified region [j .. k]
        while (j <= k) {

            // Case 1: the current element is 0
            if (nums[j] == 0) {
                /*
                 A 0 should be placed at the end of the 0 region (index i).

                 - If i < j:
                     By the invariant, [i .. j-1] contains only 1s,
                     so nums[i] must be 1. After swapping:
                     0 goes to index i, 1 moves to index j,
                     and position j is already fully processed.
                 - If i == j:
                     swap is equivalent to swap(nums[j], nums[j])
                     (swapping the element with itself),
                     so the array does not change, but the 0 region
                     can still be safely expanded.

                 In both cases, after the swap, position j does not
                 need to be re-checked.
                */
                swap(nums[i], nums[j]);
                i++;   // expand the 0 region
                j++;   // current j is processed, move forward
            }

            // Case 2: the current element is 1
            else if (nums[j] == 1) {
                /*
                 A 1 already belongs in the middle region.
                 No swapping is needed.
                */
                j++;   // expand the 1 region
            }

            // Case 3: the current element is 2
            else { // nums[j] == 2
                /*
                 A 2 should be placed at the beginning of the 2 region (index k).

                 - After swap(j, k), index k is guaranteed to contain a 2
                 - k-- expands the 2 region
                 - j must NOT advance:
                     the element swapped in from index k comes from the
                     unclassified region [j .. k], and may be 0, 1, or 2,
                     so it must be examined again
                */
                swap(nums[j], nums[k]);
                k--;   // expand the 2 region
            }
        }
    }
};


// Solution 2:
// Time Complexity: O(N)
// Space Complexity: O(1)
//
// Alternative approach:
// Traverse the array multiple times.
// In the first pass, place all 0s at the front.
// In the second pass, place all 1s after the 0s.
// The remaining elements will naturally be 2s.
// But it is not a one-pass solution.
