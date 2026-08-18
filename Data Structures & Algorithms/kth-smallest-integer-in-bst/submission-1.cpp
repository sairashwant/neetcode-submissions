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

    int result; 

    int kthSmallest(TreeNode* root, int k) {

        if(root == nullptr)
            return 0;

        kthfinder(root, k);
        return result;
    }

    void kthfinder(TreeNode* root, int& k)
    {
        if(root == nullptr)
            return;
        
        kthfinder(root->left, k);

        k--;

        if(k == 0)
            result = root->val;
        
        kthfinder(root->right, k);
        return;
    }
};
