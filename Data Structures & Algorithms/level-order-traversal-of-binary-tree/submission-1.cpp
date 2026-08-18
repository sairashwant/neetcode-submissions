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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> resultOrder;
        queue<TreeNode*> treeQ;

        treeQ.push(root);

        while(!treeQ.empty())
        {
            vector<int> level;
            int n = treeQ.size();
            
            for(int i = 0;i < n; i++)
            {
                TreeNode* temp = treeQ.front();
                treeQ.pop();
                
                if(temp!=nullptr)
                {    
                    level.push_back(temp->val);
                    treeQ.push(temp->left);
                    treeQ.push(temp->right);
                }
            }

            if(!level.empty())
                resultOrder.push_back(level);
        }

        return resultOrder;
    }
};
