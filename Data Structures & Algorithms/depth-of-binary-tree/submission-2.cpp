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
    int maxDepth(TreeNode* root) {

        int depth = 0;

        if(root == nullptr)
            return 0;
        return findDepth(root, depth);
    }

    int findDepth(TreeNode* root, int depth)
    {
        if(root == nullptr)
            return depth;

        return max(findDepth(root->left, depth+1)
        , findDepth(root->right, depth+1));
    }
};
