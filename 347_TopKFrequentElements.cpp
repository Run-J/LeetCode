
// hash map + minheap
class Solution {
public:
    // 自定义比较器：用于小顶堆，按出现次数升序排列（频率小的优先被弹出）
    class mycomparison {
    public:
        // 如果返回 true，表示 lhs 的优先级比 rhs 低（小顶堆）
        bool operator()(const pair<int, int>& lhs, const pair<int, int>& rhs) {
            return lhs.second > rhs.second;
        }
    };

    vector<int> topKFrequent(vector<int>& nums, int k) {
        // Step 1: 统计每个元素出现的次数，用哈希表 map<num, frequency>
        unordered_map<int, int> map;
        for (int i = 0; i < nums.size(); i++) {
            map[nums[i]]++;
        }

        // Step 2: 构建小顶堆，存储 pair<元素, 出现次数>
        //        使用自定义比较器，使得堆顶是频率最小的元素
        priority_queue<pair<int, int>, vector<pair<int, int>>, mycomparison> minheap;

        // Step 3: 遍历哈希表，把前 k 个出现频率最高的元素保留在小顶堆中
        for (unordered_map<int, int>::iterator it = map.begin(); it != map.end(); it++) {
            minheap.push(*it);            // 把当前元素加入堆
            if (minheap.size() > k)       // 如果堆大小超过 k，就弹出频率最小的
                minheap.pop();
        }

        // Step 4: 从小顶堆中依次取出元素，按频率从高到低填入结果数组（倒着插入）
        vector<int> result(k);
        for (int i = k - 1; i >= 0; i--) {
            result[i] = minheap.top().first;  // 提取的是元素值
            minheap.pop();
        }

        return result;
    }
};