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
    bool isBalanced(TreeNode* root) {
        // The difference between right branch's height and left branch's height must be between -1 and 1
        if (!root) {
            return true;
        }
        int leftHeight = findHeight(root->left);
        int rightHeight = findHeight(root->right);
        int diff = rightHeight - leftHeight;
        return isBalanced(root->left) && isBalanced(root->right) && diff > -2 && diff < 2;
    }

private:
    int findHeight(TreeNode* node) {
        if (!node) {
            return 0;
        }
        // Recursively find height of left and right branch, max + 1 will be the current node's height
        int leftHeight = findHeight(node->left);
        int rightHeight = findHeight(node->right);
        return max(leftHeight, rightHeight) + 1;
    }
};
