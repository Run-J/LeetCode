// Idea / Logic:
// We need the first and last position of target in a sorted array.
// A normal binary search only guarantees finding one occurrence, not the boundaries.
// So we run binary search twice:
//
// 1) Find left boundary (first occurrence):
//    - When nums[mid] == target, record mid as a candidate answer,
//      then move right = mid - 1 to continue searching on the left side.
//
// 2) Find right boundary (last occurrence):
//    - When nums[mid] == target, record mid as a candidate answer,
//      then move left = mid + 1 to continue searching on the right side.
//
// If target does not exist, both searches will keep index = -1.
//
// Time Complexity: O(log n) + O(log n) = O(log n)
// Space Complexity: O(1)
class Solution {
private:
    int binarySearch(vector<int>& nums, int target, bool isLeft) {
        int left = 0;
        int right = nums.size() - 1;
        int index = -1;

        while(left <= right) {
            int mid = left + (right - left) / 2;

            if (nums[mid] < target) {
                left = mid + 1;
            } else if (nums[mid] > target) {
                right = mid - 1;
            } else { // nums[mid] == target
                index = mid;
                if (isLeft) right = mid - 1;
                else if (!isLeft) left = mid + 1;
            }
        }

        return index;
    }

public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int left = binarySearch(nums, target, true);
        int right = binarySearch(nums, target, false);

        return {left, right};
    }
};
