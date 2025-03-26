// 27: Remove Element
// Approach 1: Brute Force (O(N^2)):
//             When a value equal to `val` is found,
//             use another for-loop to shift all elements after it one position to the left.

// Approach 2: Two-pointer technique (O(N)):
//             Use a fast pointer and a slow pointer.
//             The fast pointer scans for elements that should remain (i.e., not equal to `val`).
//             The slow pointer updates the position of the new array,
//             which will contain only elements not equal to `val`.
//             This avoids the high time complexity of nested loops.

// Key Point: Remember that the array size is fixed.
//            There is no actual deletion — the operation is done by overwriting elements.


// Solution 1: Brute Force
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        
        int size = nums.size();
        int counter = size;

        for (int i = 0; i < size; i++)
        {
            if (nums[i] == val)
            {
                for (int j = i; j < size - 1; j++)
                {
                    nums[j] = nums[j+1];
                }

                i--;
                size--;
                counter--;
            }
        }


        return counter;
    }
};


// Solution 2: Two-pointer
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        
            int size = nums.size();
            
            int slow = 0;
            for (int fast = 0; fast < size; fast++)
            {
                if (nums[fast] != val)
                {
                    nums[slow] = nums[fast];
                    slow++;
                }
            }

            return slow;

    }
};


// 27: Remove Element（移除元素）
// 解法一：暴力解法（O(N^2)）：
//         遇到 val 时，再加一层 for 循环，将 val 后面的元素全部向前移动一格。

// 解法二：双指针解法（O(N)）：
//         一个快指针和一个慢指针。
//         快指针负责查找新数组中的元素（即不等于 val 的元素），
//         新数组就是不含有目标元素的数组。
//         慢指针负责更新新数组的下标位置。
//         这种写法可以避免使用双重循环导致的高时间复杂度。

// 关键点：不要忘记数组的长度是固定的，
//         所以这里没有真正删除元素，只是进行了覆盖操作。