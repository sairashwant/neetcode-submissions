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

    unordered_map<TreeNode*, int> resultMap;

    int rob(TreeNode* root) {
        
        if(root == nullptr)
            return 0;

        if(resultMap.find(root) != resultMap.end())
            return resultMap[root];

        int result = root->val;
        if(root->left)
        {
            result += rob(root->left->left) + rob(root->left->right);
        }
        if(root->right)
        {
            result += rob(root->right->left) + rob(root->right->right);
        }

        result = max(result, rob(root->left) + rob(root->right));
        return resultMap[root]=result;
    }
};