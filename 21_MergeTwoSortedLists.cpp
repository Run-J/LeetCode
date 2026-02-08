// Logic:
// - Use a dummy head to simplify edge cases (e.g., inserting at the head).
// - Maintain a "tail" pointer to the last node of the merged list.
// - Reuse existing nodes by rewiring next pointers (no new nodes created for data).
// Time:  O(m + n)   (each node is visited once)
// Space: O(1)       (only constant extra pointers)

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {

        ListNode dummyNode(0);
        ListNode* tail = &dummyNode;  // tail always points to the last node in the merged list

        // While both lists still have nodes, always append the smaller node to the merged list.
        while (list1 && list2) {
            if (list1->val <= list2->val) {
                // Append current node from list1, then advance list1
                tail->next = list1;
                list1 = list1->next;
            } else {
                // Append current node from list2, then advance list2
                tail->next = list2;
                list2 = list2->next;
            }
            // Move tail forward to the newly appended node
            tail = tail->next;
        }

        // One list is exhausted. Since the remaining list is already sorted and all its values
        // are >= tail->val, we can directly attach the rest.
        tail->next = list1 ? list1 : list2;

        return dummyNode.next;
    }
};
