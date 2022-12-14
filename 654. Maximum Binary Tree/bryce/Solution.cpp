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
    TreeNode* constructMaximumBinaryTree(vector<int> nums) {
		// Extremely slow
		// Speed: 5.22&
		// Memory: 15.40%
        // Base case
        if (nums.size() == 0) {
            return nullptr;
        }

        // Find max
        int maxIndex = 0;
        int maxValue = nums[0];
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] > maxValue) {
                maxValue = nums[i];
                maxIndex = i;
            }
        }

        // Recursively build tree
        TreeNode* root = nullptr;
        if (maxIndex != 0) {
            if (nums.size() >= 3) {
                root = new TreeNode(
                    maxValue, 
                    constructMaximumBinaryTree(vector<int>(nums.begin(), nums.begin() + maxIndex)),
                    constructMaximumBinaryTree(vector<int>(nums.begin() + maxIndex + 1, nums.end()))
                );
            } else {
                root = new TreeNode(
                    maxValue, 
                    constructMaximumBinaryTree(vector<int>(nums.begin(), nums.begin() + 1)),
                    constructMaximumBinaryTree(vector<int>(nums.end(), nums.end()))
                );
            }
        } else {
            if (nums.size() == 1) {
                root = new TreeNode(
                    maxValue, 
                    nullptr,
                    constructMaximumBinaryTree(vector<int>(nums.begin(), nums.begin()))
                );
            } else {
                root = new TreeNode(
                    maxValue, 
                    nullptr,
                    constructMaximumBinaryTree(vector<int>(nums.begin() + 1, nums.end()))
                );
            }
        }

        return root;
    }
};