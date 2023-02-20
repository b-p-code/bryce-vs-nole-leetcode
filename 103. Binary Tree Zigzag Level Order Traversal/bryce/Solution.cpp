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
// Speed: 44.98%
// Memory: 5.22%
class Solution {
public:
    map<int, vector<int>> nodes;
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        zigzagLevelOrderAux(root, 0);
        vector<vector<int>> v;
        for (pair<int, vector<int>> p : nodes) {
            vector<int> subv;
            for (int n : p.second) {
                subv.push_back(n);
            }

            v.push_back(subv);
        }

        return v;
    }

    void zigzagLevelOrderAux(TreeNode* root, int n) {
        if (root == nullptr) {
            return;
        }
        if (n % 2 == 0) {
            auto it = nodes.find(n);
            if (it != nodes.end()) {
                it->second.push_back(root->val);
            } else {
                nodes.insert(pair<int, vector<int>>(n, vector<int>(1, root->val)));
            }
        } else {
            auto it = nodes.find(n);
            if (it != nodes.end()) {
                it->second.insert(it->second.begin(), root->val);
            } else {
                nodes.insert(pair<int, vector<int>>(n, vector<int>(1, root->val)));
            }
        }

        zigzagLevelOrderAux(root->left, n + 1);
        zigzagLevelOrderAux(root->right, n + 1);
    }
};