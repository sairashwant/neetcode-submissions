class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> permutations;
        vector<int> temp;
        dfs(nums, permutations, temp);
        return permutations;
    }

    void dfs(vector<int>& nums, vector<vector<int>> &permutations, vector<int> temp)
    {
        if(temp.size() == nums.size())
        {
            permutations.push_back(temp);
            return;
        }

        for(auto num : nums)
        {
            if(find(temp.begin(), temp.end(), num) != temp.end())
                continue;
            
            temp.push_back(num);

            dfs(nums, permutations, temp);

            temp.pop_back();
        }
    }
};
