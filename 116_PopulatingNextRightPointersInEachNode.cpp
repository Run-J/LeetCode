/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

// 在单层遍历的时候记录一下本层的头部节点，然后在遍历的时候让前一个节点指向本节点就可以了
class Solution {
public:
    Node* connect(Node* root) {
        
        queue<Node*> que;
        if (root != NULL) que.push(root);

        while (!que.empty()) {
            int rowSize = que.size();
            Node* preNode = NULL;
            Node* curNode = NULL;

            for (int i = 0; i < rowSize; i++) {
                if (i == 0) {
                    preNode = que.front();
                    que.pop();
                    curNode = preNode;
                }
                else {
                    curNode = que.front();
                    que.pop();
                    preNode->next = curNode;
                    preNode = curNode;
                }

                if (curNode->left) que.push(curNode->left);
                if (curNode->right) que.push(curNode->right);
            }

        }

        return root;
    }
};