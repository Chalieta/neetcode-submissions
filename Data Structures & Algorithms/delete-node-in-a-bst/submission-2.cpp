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
    TreeNode* deleteNode(TreeNode* root, int key) {
        if (!root) {
            return nullptr;
        }

        if (key > root->val) {
            root->right = deleteNode(root->right, key);
        } else if (key < root->val) {
            root->left = deleteNode(root->left, key);
        } else {
            if (!root->left && !root->right) { // The node that will be removed has 0 child
                return nullptr;
            } else if (root->left && !root->right) { // The node that will be removed only has left child
                return root->left;
            } else if (!root->left && root->right) { // The node that will be removed only has right child
                return root->right;
            } else { // The node that will be removed has two children
                // Find the minimum value of the right branch
                int minVal = minNode(root->right);
                // Replace root->val with minVal
                root->val = minVal;
                // Delete node with minVal and update right branch
                root->right = deleteNode(root->right, minVal);
            }
        }

        return root;
    }

private:
    int minNode(TreeNode* root) {
        while (root->left != nullptr) {
            root = root->left;
        }

        return root->val;
    }
};