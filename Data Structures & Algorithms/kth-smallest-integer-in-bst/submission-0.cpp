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
    int kthSmallest(TreeNode* root, int k) {

        if(root == nullptr)
            return 0;

        vector<int> counter(2,0);
        counter[0] = k;
        kthfinder(root, k, counter);
        return counter[1];
    }

    void kthfinder(TreeNode* root, int k, vector<int>& counter)
    {
        if(root == nullptr)
            return;
        
        kthfinder(root->left, k, counter);

        counter[0]--;

        if(counter[0] == 0)
            counter[1] = root->val;
        
        kthfinder(root->right, k, counter);
        return;
    }
};
