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
        
        if(root == nullptr) return root;

        if(key < root->val)
            root->left = deleteNode(root->left, key);

        if(key > root->val)
            root->right = deleteNode(root->right, key);

        if(key == root->val)
        {
            if(root->left == nullptr) return root->right;
            if(root->right == nullptr) return root -> left;

            TreeNode* curr = root->right;
            while(curr->left)
            {
                curr = curr->left;
            }

            root->val = curr->val;
            root->right = deleteNode(root->right, root->val);
        }

        return root;
    }
};