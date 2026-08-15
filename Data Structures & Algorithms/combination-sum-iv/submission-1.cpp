class Solution {
public:
    unordered_map<int, int> dp;
    int combinationSum4(vector<int>& nums, int target) {
        return searchComb(nums, target, dp);
    }

    int searchComb(vector<int>& nums, int target, unordered_map<int, int> &dp)
    {
        if(target == 0) return 1;

        if(target < 0)  return 0;

        if(dp.find(target) != dp.end()) return dp[target];

        int count = 0;

        for(auto n : nums)
        {
            count += searchComb(nums, target - n, dp);
        }

        return dp[target]=count;
    }
};