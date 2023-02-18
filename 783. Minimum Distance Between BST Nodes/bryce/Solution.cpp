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

// IMO a worse solution than my original, but ran faster
// Speed: 63.90%
// Memory: 7%
class Solution {
public:
    int minDiffInBST(TreeNode* root) {
        vector<int> nv = getValues(root);
        int mv = 10000000;
        for (int i = 0; i < nv.size() - 1; i++) {
            for (int j = i + 1; j < nv.size(); j++) {
                if (abs(nv[i] - nv[j]) < mv) {
                    mv = abs(nv[i] - nv[j]);
                }
            }
        }

        return mv;
    }

    vector<int> getValues(TreeNode* node) { 
        if (node == nullptr) {
            return vector<int>(0);
        } else {
            vector<int> lr;
            lr.push_back(node->val);
            vector<int> l;
            vector<int> r;
            if (node->left) {
                l = getValues(node->left);
            }
            if (node->right) {
                r = getValues(node->right);
            }
            lr.insert(lr.end(), l.begin(), l.end());
            lr.insert(lr.end(), r.begin(), r.end());
            return lr;
        }
    }
};