

// ✅ Solution 1: General Approach （常规写法）
//
// First, remove all matching nodes at the head. Then use a pointer `current`
//     to traverse the list and delete any node with value equal to `val`.
//
// 先处理链表头部的所有待删除节点。然后使用 `current` 指针遍历链表，
//     删除值等于 `val` 的节点。

class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        
        ListNode* temp = NULL;
        while (head != NULL && head->val == val)
        {
            temp = head;
            head = head->next;
            delete(temp);
        }


        ListNode* current = head; // Assign head to current is a best practice
        while (current != NULL && current->next != NULL)
        {
            if (current->next->val == val)
            {
                temp = current->next;
                current->next = current->next->next;
                delete(temp);
            }
            else
            {
                current = current->next;
            }
        }

        return head;

    }
};



// ✅ Solution 2: Use Dummy Node （使用虚拟头节点）
//
// Introduce a dummy node before the real head to simplify edge cases,
//     especially when the head node needs to be deleted.
//     This avoids special handling for head deletion.
//
// 引入一个虚拟头节点 dummyNode，连接到原始链表头部，
//     可以统一处理所有节点的删除逻辑，避免特殊处理头节点删除的情况。

class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {

        ListNode* dummyNode = new ListNode(0);
        dummyNode->next = head;
        ListNode* current = dummyNode;

        while (current->next != NULL)
        {
            if (current->next->val == val)
            {
                ListNode* temp = current->next;
                current->next = current->next->next;
                delete(temp);
            }
            else
            {
                current = current->next;
            }
        }

        return dummyNode->next;
    }
};


// ✅ Solution 3: Recursion （递归写法）
//
// Recursively process the list:
//     - If the current node should be deleted, return the result of removing from its next.
//     - Else, keep the node and recurse on its next.
//
// 递归地处理链表：
//     - 如果当前节点的值等于 `val`，则删除该节点，递归处理下一个节点；
//     - 否则保留当前节点，递归处理它的下一个节点。

class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {

        if (head == nullptr)
        {
            return nullptr;
        }

        if (head->val == val)
        {
            ListNode* newHead = removeElements(head->next, val);
            delete head;
            return newHead;
        }
        else
        {
            head->next = removeElements(head->next, val);
            return head;
        }
    }
};