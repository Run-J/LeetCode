/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int lenA = 0;
        int lenB = 0;
        ListNode* curA = headA;
        ListNode* curB = headB;
        while (curA != nullptr)
        {
            lenA++;
            curA = curA->next;
        }
        while (curB != nullptr)
        {
            lenB++;
            curB = curB->next;
        }

        curA = headA; // reset the current pointer point to the head
        curB = headB;

        if (lenB > lenA) // make the curA/lenA always refer to the longer one linked list
        {
            swap(lenA, lenB);
            swap(curA, curB);
        }

        int gap = lenA - lenB;
        // Let curA and curB be at the same starting point
        while (gap--)
        {
            curA = curA->next;
        }

        while (curA != nullptr && curB != nullptr)
        {
            if (curA == curB)
            {
                return curA;
            }

            curA = curA->next;
            curB = curB->next;
        }

        return nullptr;
    }
};