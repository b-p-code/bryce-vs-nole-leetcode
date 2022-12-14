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

class Pair {
    public:
        int index;
        int value;

        Pair(int index, int value) {
            this->index = index;
            this->value = value;
        }
};

bool operator<(const Pair&p1, const Pair& p2) {
    return p1.value < p2.value;
}

class Solution {
public:
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
		// Marginally better now
		// Speed: 15.13%
		// Memory: 8.24%
        // THOUGHT PROCESS - we always insert the max value into the tree
        // where it is positioned within the tree is related to its index

        TreeNode* root = nullptr;

        priority_queue<Pair> q;
        for (int i = 0; i < nums.size(); i++) {
            q.push(Pair(i, nums[i]));
        }

        while (!q.empty()) {
            insertNode(root, q.top());
            q.pop();
        }

        replaceNodes(root, nums);

        return root;
    }

    void insertNode(TreeNode* &node, Pair p) {
        if (node == nullptr) {
            node = new TreeNode(p.index);
            return;
        } else if (node->val < p.index) {
            insertNode(node->right, p);
        } else {
            insertNode(node->left, p);
        }
    }

    void replaceNodes(TreeNode* &node, vector<int> nums) {
        if (node != nullptr) {
            node->val = nums[node->val];
            replaceNodes(node->left, nums);
            replaceNodes(node->right, nums);
            return;
        }
    }
};