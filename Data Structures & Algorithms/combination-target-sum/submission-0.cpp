class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<vector<int>> result;
        vector<int> temp;
        sort(nums.begin(), nums.end());
        dfs(nums, target, result, temp, 0);
        return result;
    }

    void dfs(vector<int> &nums, int target, vector<vector<int>> &result, vector<int> &temp, int start)
    {
        if(target == 0)
        {
            result.push_back(temp);
            return;
        }

        if(start >= (int)nums.size() || target < 0) return;  

        for(int i = start; i < nums.size(); i++)
            {
                if(nums[i]>target) break;
                temp.push_back(nums[i]);
                dfs(nums, target-nums[i], result, temp, i);
                temp.pop_back();
            }
        
        return;
    }

};
