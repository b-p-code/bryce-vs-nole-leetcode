/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    // Speed: 100%
    // Space: 85.78%
    TreeNode* invertTree(TreeNode* root) {
        // Base case
        if (root == nullptr) {
            return nullptr;
        }

        // Invert left and right nodes recursively
        /* No need to store the return values, since we are inverting in-place */
        if (root->left) {
            invertTree(root->left);
        }
        if (root->right) {
            invertTree(root->right);
        }

        // Invert the tree
        TreeNode* temp = root->left;
        root->left = root->right;
        root->right = temp;

        return root;
    }
};