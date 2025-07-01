/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

// Solution 1: 
// - use the hash set, to record the nodes that we have visited. In another word,
// - as long as current address of current node is one of node we have visited, then that's mean 
// - there is a circle.
// 
// - but useing if hash set, the memory complexity is not O(1), so we can improve it.
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        
        unordered_set<ListNode*> visited;

        ListNode* cur = head;

        while (cur) {
            
            if (visited.count(cur)) {
                return cur;
            }

            visited.insert(cur);
            cur = cur->next;
        }

        return nullptr;

    }
};


// Solution 2:

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {

        // 定义快慢指针，均从头结点出发
        ListNode* fast = head;
        ListNode* slow = head;

        // 快慢指针遍历链表
        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;           // 慢指针走一步
            fast = fast->next->next;     // 快指针走两步

            // 快慢指针相遇，说明有环
            if (slow == fast) {
                // 定义两个指针：一个从相遇点出发，一个从头结点出发
                ListNode* index1 = fast;
                ListNode* index2 = head;

                // 两个指针每次各走一步，最终会在环的入口相遇
                while (index1 != index2) {
                    index1 = index1->next;
                    index2 = index2->next;
                }

                // 相遇点即为环的入口
                return index2;
            }
        }

        // 如果没有环，直接返回nullptr
        return nullptr;
    }
};

// ✅ 判断链表是否有环 —— 快慢指针法（Floyd 判圈法）：
//  - fast 一次走两步，slow 一次走一步。
//  - 若链表有环，fast 一定会在环内追上 slow（类似圆形操场两人跑步问题）。
//  - 为什么一定会相遇？
//  - 因为每走一步，fast 相对于 slow 实际是向前逼近一步。
//  - 环内节点有限，最多走一圈就会相遇。

// ✅ 如何找环的入口：
// 设：
//  x 为头结点到环入口的距离；
//  y 为环入口到相遇点的距离；
//  z 为相遇点到环入口的距离；

// fast 比 slow 多走了 n 圈，即走了 x + y + n(y + z)，slow 走了 x + y。
// 因为 fast 速度是 slow 的两倍，有：
//                                       2(x + y) = x + y + n(y + z)
// 两边各自消掉一个（x+y）：                x + y = n (y + z)
// 因为要找环形的入口，那么要求的是x，因为x表示 头结点到 环形入口节点的的距离。
// 所以要求x ，将x单独放在左面：             x = n (y + z) - y ,
// 再从n(y+z)中提出一个 （y+z）来， 推出：  x = (n - 1)(y + z) + z
// 即：从头出发的指针与从相遇点出发的指针（都走一步），在环入口相遇。
// 先拿n为1的情况来举例，意味着fast指针在环形里转了一圈之后，就遇到了 slow指针了。
// 当 n为1的时候，公式就化解为 x = z，
// 这就意味着，从头结点出发一个指针，从相遇节点 也出发一个指针，这两个指针每次只走一个节点， 那么当这两个指针相遇的时候就是 环形入口的节点。
// 也就是在相遇节点处，定义一个指针index1，在头结点处定一个指针index2。
// 让index1和index2同时移动，每次移动一个节点， 那么他们相遇的地方就是 环形入口的节点。

// ⏱ 复杂度分析：
// 时间复杂度：O(n) —— 最多走 2n 步（一次找环 + 一次找入口）。
// 空间复杂度：O(1) —— 只用了常数级别的指针变量。
