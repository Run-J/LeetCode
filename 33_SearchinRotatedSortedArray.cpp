// Logic:
// 1：Since the array is rotated, it is not globally sorted, but at least one half is always sorted. We locate that sorted half 
// 2: and use its value range to determine whether the target lies inside it. 
// 3: Then we discard the other half and continue binary search.
// Time Complexity: O(log n)

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;

        while (left <= right) {
            int mid = left + (right - left) / 2;

            // If target is found
            if (nums[mid] == target) return mid;

            // Check if the left half is sorted
            if (nums[left] <= nums[mid]) { // Using <= here handles edge cases like [3,1] (target = 1), where left == mid and the left half should still be considered sorted.
                // If target lies within the sorted left half
                if (nums[left] <= target && target < nums[mid]) // The boundary condition (<=) is necessary for cases like [5,1,3] with target = 5 to avoid discarding the correct half.
                    right = mid - 1;
                else
                    left = mid + 1;
            } 
            // Otherwise, the right half must be sorted
            else {
                // If target lies within the sorted right half
                if (nums[mid] < target && target <= nums[right])
                    left = mid + 1;
                else
                    right = mid - 1;
            }
        }

        return -1; // Target not found
    }
};
