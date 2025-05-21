/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

// 和标准的二叉树层序遍历区别，只是一个Node多了一个child
class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        
        vector<vector<int>> result;
        if (root == NULL) return result;

        queue<Node*> que;
        que.push(root);

        while (!que.empty()) {
            int rowSize = que.size();
            vector<int> row;

            for (int i = 0; i < rowSize; i++) {
                Node* node = que.front();
                que.pop();

                row.push_back(node->val);
                for (int i = 0; i < node->children.size(); i++) {
                    if (node->children[i]) que.push(node->children[i]);
                }
            }

            result.push_back(row);
        }
        
        return result;
    }
};