// Logic:
// We simulate elementary school addition digit by digit.
// Use two pointers to traverse both lists.
// At each step, compute sum = x + y + carry.
// Create a new node with (sum % 10).
// Update carry = sum / 10.
// Continue until both lists end AND carry becomes 0. 
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
      
        ListNode dummyNode(0);
        ListNode* tail = &dummyNode;

        ListNode* p1 = l1;
        ListNode* p2 = l2;

        // Carry from previous digit addition
        int carry = 0;

        // Continue if:
        // - either list still has nodes
        // - OR there is remaining carry
        while (p1 != nullptr || p2 != nullptr || carry != 0) {
          
            // If pointer is null, treat its value as 0
            int x = (p1 != nullptr) ? p1->val : 0;
            int y = (p2 != nullptr) ? p2->val : 0;

            int sum = x + y + carry;
            carry = sum / 10;   // Update carry for next iteration

            // Create new node with current digit (ones place)
            ListNode* newNode = new ListNode(sum % 10);

            // Append new node to result list
            tail->next = newNode;

            // Move tail forward
            tail = tail->next;

            // Move p1 and p2 forward if possible
            if (p1 != nullptr) p1 = p1->next;
            if (p2 != nullptr) p2 = p2->next;
        }

        // Return the actual head (skip dummy node)
        return dummyNode.next;
    }
};
