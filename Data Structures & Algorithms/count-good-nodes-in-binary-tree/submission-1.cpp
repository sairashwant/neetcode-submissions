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
    int goodNodes(TreeNode* root) {
        int max = INT_MIN;
        int count = 0;
        dfs(root, max, count);
        return count;
    }

private:
    void dfs(TreeNode* node, int max, int &count)
    {
        if(node == nullptr)
        {
            return;
        }

        if(node -> val >= max)
            {
                count++;
                max = node->val;
            }

        dfs(node->left, max, count);
        dfs(node->right, max, count);
    }
};
