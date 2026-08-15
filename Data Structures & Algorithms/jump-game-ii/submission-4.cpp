class Solution {
public:
    int jump(vector<int>& nums) {
        vector<int> dp(nums.size()+1, -1);
        return f(nums, 0, dp);
    }

    int f(vector<int> &nums, int i, vector<int> &dp)
    {
        int ans = INT_MAX;

        if(i>=nums.size() - 1)
            return 0;

        if(dp[i] != -1)   return dp[i];
        for(int jump = 1; jump <= nums[i]; jump++)
        {
            int next = f(nums, i+jump, dp);
            if(next != INT_MAX)
                ans = min(ans, 1 + next);
        }

        return dp[i]=ans;

    }
};
