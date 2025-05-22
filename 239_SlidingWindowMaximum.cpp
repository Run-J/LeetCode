

// 核心策略：维护一个单调递减队列
//  -- 队列里存的是数组***索引***
//  -- 队列中索引对应的值是从大到小排列
//  -- 每次窗口滑动，只需看队首就是当前最大值
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        
        deque<int> dq;            // 存储元素的“索引”，维护一个「单调递减」队列； 注意：存的是索引，不是值
        vector<int> result;       // 存储每个窗口的最大值

        for (int i = 0; i < nums.size(); i++) {

            // 1. 移除已滑出窗口的索引（保证队首元素在窗口范围内）
            if (!dq.empty() && dq.front() <= i - k) {
                dq.pop_front();
            }

            // 2. 保证队列单调递减：
            // 当前元素比队尾所指的元素大时，丢掉队尾小的元素
            while (!dq.empty() && nums[i] > nums[dq.back()]) {
                dq.pop_back();
            }

            // 3. 将当前元素索引加入队列（注意是索引，不是值）
            dq.push_back(i);

            // 4. 从第一个满窗口开始记录结果：
            // 此时队首的索引指向的元素是当前窗口最大值
            if (i >= k - 1) {
                result.push_back(nums[dq.front()]);
            }
        }

        return result;
    }
};
