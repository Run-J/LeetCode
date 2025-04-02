/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */


// ✅ Solution 1: Iterative (using two pointers)
// - Use two pointers: `pre` (previous node), `cur` (current node)
// - At each step:
//   1. Save the next node (temp)
//   2. Reverse the link: cur->next = pre
//   3. Move both pointers forward
// - Finally, `pre` becomes the new headclass Solution {
public:
    ListNode* reverseList(ListNode* head) {
        
        ListNode* pre = nullptr;
        ListNode* cur = head;

        while (cur)
        {
            ListNode* temp = cur->next;
            cur->next = pre;
            pre = cur;
            cur = temp;
        }

        return pre;
    }
};



// ✅ Solution 2: Recursive
// - Base case: if current node is null, return pre (which is the new head)
// - Recursive step:
//   1. Save next node (temp)
//   2. Reverse current pointer: cur->next = pre
//   3. Recurse with new pre and cur
// - The reversal happens as the recursion unwinds back (随着递归逐层返回，链表指针逐个完成反转)
class Solution {
public:

    ListNode* reverseList(ListNode* head) 
    {
        return reverse(nullptr, head);
    }


    ListNode* reverse(ListNode* pre, ListNode* cur)
    {
        if (cur == nullptr)
        {
            return pre;
        }

        ListNode* temp = cur->next;
        cur->next = pre;
        return reverse(cur, temp);
    }
};