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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> result;
        queue<TreeNode*> q;

        if (root) {
            q.push(root);
        }

        while(!q.empty()) {
            vector<int> level;
            int levelSize = q.size();
            for (int i = 0; i < levelSize; ++i) {
                TreeNode* current = q.front();
                level.push_back(current->val); // Add queue member to level
                // Add queue member's children to the queue 
                // levelSize will prevent the children from being processed yet
                if (current->left) {
                    q.push(current->left);
                }
                if (current->right) {
                    q.push(current->right);
                }

                q.pop();
            }
            result.push_back(level);
        }

        return result;
    }
};
