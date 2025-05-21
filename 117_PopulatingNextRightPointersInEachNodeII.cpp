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

class Solution {
public:
    Node* connect(Node* root) {
        
        if (root == NULL) return root;

        queue<Node*> que;
        que.push(root);

        while (!que.empty()) {
            int rowSize = que.size();
            Node* preNode = NULL;
            Node* curNode = NULL;

            for (int i = 0; i < rowSize; i++) {
                Node* node = que.front();
                que.pop();

                if (i == 0) {
                    preNode = node;
                    curNode = node;
                }
                else {
                    curNode = node;
                    preNode->next = curNode;
                    preNode = curNode;
                }
                
                if (curNode->left) que.push(curNode->left);
                if (curNode->right) que.push(curNode->right);
            }

            curNode->next = NULL;
        }

        return root;

    }
};