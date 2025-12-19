// Logic Strategy: 
// ----------------------------------
// We use a helper function to traverse from the root to every leaf.
// Key Concept: "Backtracking"
// Because we pass the 'path' vector by reference (to save memory),
// we must add the current node when entering, and REMOVE it (pop_back)
// when returning. This ensures the path is clean for the next branch.
class Solution {
public:
    void traversal(TreeNode* node, vector<int>& path, vector<string>& result) {
        // 1. Process Current Node
        // Add the current node to our path history (e.g., path becomes [1, 2])
        path.push_back(node->val);

        // 2. Base Case: Are we at a Leaf Node?
        // Definition: A leaf has NO left child AND NO right child.
        if (node->left == NULL && node->right == NULL) {
            string sPath;
            
            // Convert the integer path vector [1, 2, 5] into the required string "1->2->5"
            for (int i = 0; i < path.size(); i++) {
                sPath += to_string(path[i]);
                // Add the arrow "->" only if it's NOT the last element
                if (i != path.size() - 1) {
                    sPath += "->";
                }
            }
            // Store the completed path string in our result list
            result.push_back(sPath);
            
            return;
        }

        // 3. Recursive Step (Left)
        if (node->left != NULL) {
            traversal(node->left, path, result);
            
            // *** BACKTRACKING ***
            // We just returned from exploring the entire Left subtree.
            // We must now remove the Left node from the 'path' so that we can
            // correctly use this same 'path' vector to explore the Right subtree.
            path.pop_back(); 
        }

        // 4. Recursive Step (Right)
        if (node->right != NULL) {
            traversal(node->right, path, result);
            
            // *** BACKTRACKING ***
            // Same logic: We are done with the Right subtree. Remove the node
            // to return the 'path' to its state before we entered this branch.
            path.pop_back();
        }
    }

    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> result;
        vector<int> path;

        // Edge Case: If tree is empty, return empty result immediately.
        // (Without this check, traversal(NULL...) would crash on node->val)
        if (root == NULL) return result;

        traversal(root, path, result);
        return result;
    }
};
