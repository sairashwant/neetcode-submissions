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
    int diameterOfBinaryTree(TreeNode* root) {
        int result = 0;
        findDia(root, result);
        return result;
    }

    int findDia(TreeNode* root, int &result)
    {
        if(root == nullptr)
        {
            return 0;
        }

        int left = findDia(root->left, result);
        int right = findDia(root->right, result);

        result = max(result, left + right);

        return 1 + max(left, right);
    }
};
