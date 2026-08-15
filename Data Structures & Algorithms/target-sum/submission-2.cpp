class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        
        int ways = 0;
        vector<vector<int>> dp(nums.size()+1, vector<int>(2001, -1));
        ways = bfs(nums, target, 0, ways, 0, dp, 1000);
        return ways;
    }

    int bfs(vector<int>& nums, int target, int i, int count, int sum, vector<vector<int>> &dp, int offset)
    {
        if(i >= nums.size())
            return sum == target ? 1 : 0;
        
        if(dp[i][offset+sum] != -1)    
            return dp[i][offset+sum];

        int add = bfs(nums, target, i+1, count, sum + nums[i], dp, offset);
        int diff = bfs(nums, target, i+1, count, sum - nums[i], dp, offset);

        return dp[i][offset+sum] = add + diff;
    }
};
