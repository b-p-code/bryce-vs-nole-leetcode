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
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
		// Better solution, still slow
		// Speed: 5.22%
		// Memory: 11.59%

        // Base case
        if (nums.size() == 0) {
            return nullptr;
        }

        // Recursively build tree
        int i = findMax(0, nums.size(), nums);
        vector<int> left = getSubVector(0, i, nums);
        vector<int> right = getSubVector(i + 1, nums.size(), nums);
        TreeNode* root = new TreeNode(
            nums[i],
            constructMaximumBinaryTree(left),
            constructMaximumBinaryTree(right)
        );

        return root;
    }

    int findMax(int begin, int end, vector<int> nums) {
        // Find max
        int maxIndex = 0;
        int maxValue = nums[0];
        for (int i = begin; i < end; i++) {
            if (nums[i] > maxValue) {
                maxValue = nums[i];
                maxIndex = i;
            }
        }

        return maxIndex;
    }

    vector<int> getSubVector(int begin, int end, vector<int> nums) {
        vector<int> temp;
        if (end - begin > nums.size()) {
            temp.clear();
            return temp;
        }

        temp = vector<int>(nums.begin() + begin, nums.begin() + end);
        return temp;
    }
};