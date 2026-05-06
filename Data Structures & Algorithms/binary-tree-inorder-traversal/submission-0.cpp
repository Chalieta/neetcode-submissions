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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> results;
        return traverse(root, results);
    }

private :
    vector<int> traverse(TreeNode* root, vector<int> results) {
        if (!root) {
            return results;
        }

        results = traverse(root->left, results);
        results.push_back(root->val);
        results = traverse(root->right, results);

        return results;
    }
};