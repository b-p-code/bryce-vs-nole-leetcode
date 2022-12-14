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
		// massive improvement - researched iterative binary tree code
		// Speed: 90.83%
		// Memory: 85.46%
		
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

    void insertNode(TreeNode* &root, Pair p) {
        // Insert a node iteratively
        // There's probably a better way to do this
        TreeNode* node = root;
        TreeNode* prevNode = node;
        bool left = false;
        bool right = false;

        while (node != nullptr) {
            if (node->val < p.index) {
                left = false;
                right = true;
                prevNode = node;
                node = node->right;
            } else {
                left = true;
                right = false;
                prevNode = node;
                node = node->left;
            }
        }

        if (right) {
            prevNode->right = new TreeNode(p.index);
        } else if (left) {
            prevNode->left = new TreeNode(p.index);
        } else {
            root = new TreeNode(p.index);
        }
    }

    void replaceNodes(TreeNode* root, vector<int> nums) {
        // Traverse nodes iteratively
        stack<TreeNode*> s;
        TreeNode* node = root;
        while (node != nullptr || s.size() > 0)
        {
            while (node != nullptr)
            {
                s.push(node);
                node = node->left;
            }

            node = s.top();
            s.pop();
 
            node->val = nums[node->val];

            node = node->right;
        }
    }
};