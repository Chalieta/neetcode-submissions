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
        deque<TreeNode*> d; // We use deque because we want to access the back of the queue;
        if (root) {
            d.push_back(root);
        }
        while (!d.empty()) {
            int levelSize = d.size();
            result.push_back(d.back()->val); // Record the back of the level

            // Iterate through the deque to add the children and remove the current level members
            for (int i = 0; i < levelSize; ++i) {
                TreeNode* curr = d.front();
                if (curr->left) {
                    d.push_back(curr->left);
                }
                if (curr->right) {
                    d.push_back(curr->right);
                }
                d.pop_front();
            }
        }

        return result;
    }
};
