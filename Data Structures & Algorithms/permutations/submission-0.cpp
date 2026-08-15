class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> permutations;
        vector<int> temp;
        dfs(nums, permutations, temp, 0);
        return permutations;
    }

    void dfs(vector<int>& nums, vector<vector<int>> &permutations, vector<int> temp, int start)
    {
        if(start==(int)nums.size())
            {
                permutations.push_back(nums);
                return;
            }
        for(int i=start; i < nums.size(); i++)
        {
            swap(nums[start], nums[i]);
            dfs(nums, permutations, temp, start+1);
            swap(nums[start], nums[i]);
        }
    }
};
