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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        
        unordered_map<int, int> hashmap;

        for(int i=0; i < inorder.size(); i++)
        {
            hashmap[inorder[i]] = i;
        }

        return f(preorder, inorder, hashmap, 0, 0, inorder.size()-1);
    }

    TreeNode* f(vector<int>& preorder, vector<int>& inorder, unordered_map<int, int> hashmap, int root, int left, int right)
    {
        int rootval = preorder[root];

        int mid = hashmap[rootval];

        TreeNode* node = new TreeNode(rootval);

        if(mid > left)
            node->left = f(preorder, inorder, hashmap, root+1, left, mid-1);

        if(mid < right)
            node->right = f(preorder, inorder, hashmap, root+mid-left+1, mid+1, right);

        return node;
    }
};
