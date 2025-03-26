// 977. Squares of a Sorted Array

// Solution Explanation:
//      Since the original array is sorted in increasing order and may contain negative numbers,
//      the largest squared value may appear at either end of the array.
//
//      Therefore, we can use a two-pointer approach:
//      Set the `left` pointer at the beginning of the array and the `right` pointer at the end.
//
//      At each step, compare `nums[left]^2` and `nums[right]^2`, and insert the larger one
//      into the result array from the back.
//      Move the corresponding pointer inward, and repeat until all elements are processed.
//
//      By filling the result array from right to left, we ensure the final result is sorted
//      in non-decreasing order, without needing to sort afterward.


class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        
        vector<int> result(nums.size(), 0); // initialize a result array
        int resultIndex = result.size() - 1;

        for (int left = 0, right = nums.size() - 1; left <= right;  )
        {
            if (nums[left] * nums[left] > nums[right] * nums[right])
            {
                result[resultIndex--] = nums[left] * nums[left];
                left++;
            }
            else 
            {
                result[resultIndex--] = nums[right] * nums[right];
                right--;
            }
        }

        return result;
    }
};

// 977. Squares of a Sorted Array （有序数组的平方）

// 解法说明：
// 由于原数组是递增的，并且可能包含负数，平方后数值的最大值可能出现在数组的两端。
// 因此，我们可以使用一个双指针策略：
// 设置 left 指针指向数组起始位置，right 指针指向数组末尾；
// 每次比较 nums[left]^2 和 nums[right]^2 的大小，将较大的数放入新数组的末尾；
// 指针向中间收缩，直到所有元素都处理完；
// 通过从右向左填充结果数组，我们可以保证结果是递增的，无需再排序；
