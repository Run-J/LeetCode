// 704: Binary Search
// Prerequisites for using binary search:
//      1: The array must be sorted
//      2: The array must contain no duplicate elements, because if there are duplicates, 
//         the index returned by binary search may not be unique

// Common pitfalls:
//      1: Poor handling of boundaries, often caused by not clearly defining the search interval. 
//         The definition of the interval is an invariant.
//      2: During binary search, you must maintain the interval definition as an invariant. 
//         Every update to the boundary must strictly follow this rule — this is the loop invariant principle.
//      3: mid = (left + right) / 2 may cause integer overflow in some cases, 
//         so it is safer to use: mid = left + (right - left) / 2

// Overall strategy for writing binary search:
//      There are two common ways to define the interval for binary search:
//      Left-closed, right-closed interval [left, right]
//      Left-closed, right-open interval [left, right)

// When writing loops and updating boundaries, always follow the interval definition you’ve chosen 
// to ensure correctness.


class Solution {
public:
    int search(vector<int>& nums, int target) {
        
        int left = 0;
        int right = nums.size();

        while (left < right)
        {
            int mid = (left + right) / 2;

            if (nums[mid] < target)
            {
                left = mid + 1;
            }
            else if (nums[mid] > target)
            {
                right = mid;
            }
            else
            {
                return mid;
            }
        }

        return -1;

    }
};


// 704: Binary Search (二分查找)
// 使用二分法的前提：
//      1： 要求数组为有序数组
//      2： 要求数组中无重复元素，因为一旦有重复元素，使用二分查找法返回的元素下标可能不是唯一的

// 易错点：
//      1： 对边界处理不好，常见原因是对区间的定义没有想清楚。区间的定义就是不变量。
//      2： 在二分查找的过程中，必须保持区间定义这个不变量。每一次边界的更新都必须严格遵循这个规则 —— 这就是循环不变量原则。
//      3： mid = (left + right) / 2 在某些情况下可能会导致整数溢出，因此应使用更安全的写法：mid = left + (right - left) / 2

// 写二分查找的整体思路：
//      二分查找常用的区间定义有两种：
//      左闭右闭区间 [left, right]
//      左闭右开区间 [left, right)

// 在编写循环和更新边界时，一定要始终按照选择的区间定义进行处理，确保程序的正确性。