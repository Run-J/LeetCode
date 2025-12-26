
// Logic:
// Step 1: If the array size is zero, it means the current node is empty.
// Step 2: If the array is not empty, take the last element of the postorder array as the root value.
// Step 3: Find the position of this root value in the inorder array; this position is used as the split point.
//
// Step 4: Split the inorder array into left and right subarrays
// (be careful not to reverse the order — always split the inorder array first).
// Step 5: Split the postorder array into left and right subarrays based on the size of the left inorder subarray.
//
// Step 6: Recursively process the left and right subtrees.
  
class Solution {
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {

        // If postorder is empty, the tree (or subtree) is empty
        if (postorder.empty()) return NULL;

        // The last element in postorder traversal is the root of the tree
        int rootValue = postorder.back();
        TreeNode* root = new TreeNode(rootValue);

        // If there is only one node, return it directly
        if (postorder.size() == 1) return root;

        // Find the index of the root in inorder traversal
        int delimiterIndex = 0;
        for (int i = 0; i < inorder.size(); i++) {
            if (inorder[i] == rootValue) {
                delimiterIndex = i;
                break;
            }
        }

        // Split inorder into left and right subtrees using the root index
        vector<int> inorderLeft(inorder.begin(), inorder.begin() + delimiterIndex);
        vector<int> inorderRight(inorder.begin() + delimiterIndex + 1, inorder.end());

        // Remove the root element from postorder
        postorder.pop_back();

        // Split postorder into left and right subtrees
        // The size of the left subtree is determined by inorderLeft.size()
        vector<int> postorderLeft(postorder.begin(),
                                  postorder.begin() + inorderLeft.size());
        vector<int> postorderRight(postorder.begin() + inorderLeft.size(),
                                   postorder.end());

        // Recursively build left and right subtrees
        root->left = buildTree(inorderLeft, postorderLeft);
        root->right = buildTree(inorderRight, postorderRight);

        return root;
    }
};
