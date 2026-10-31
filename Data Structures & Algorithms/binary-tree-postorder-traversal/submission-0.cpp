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
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> res;
        stack<TreeNode*> stk;
        stack<bool> visited;

        stk.push(root);
        visited.push(false);

        while (!stk.empty()) {
            TreeNode* cur = stk.top();
            bool v = visited.top();
            stk.pop();
            visited.pop();

            if (cur) {
                if (v) {
                    res.push_back(cur->val);
                } else {
                    stk.push(cur);
                    visited.push(true);
                    stk.push(cur->right);
                    visited.push(false);
                    stk.push(cur->left);
                    visited.push(false);
                }
            }
        }

        return res;
    }
};