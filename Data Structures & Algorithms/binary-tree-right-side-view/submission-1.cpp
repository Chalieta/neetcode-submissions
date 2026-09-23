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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> result;
        deque<TreeNode*> dq;

        if (root) {
            dq.push_back(root);
        }

        while (!dq.empty()) {
            int levelSize = dq.size();
            result.push_back(dq.back()->val);

            for (int i = 0; i < levelSize; ++i) {
                TreeNode* cur = dq.front();
                if (cur->left) {
                    dq.push_back(cur->left);
                }
                if (cur->right) {
                    dq.push_back(cur->right);
                }
                dq.pop_front();
            }
        }

        return result;
    }
};
