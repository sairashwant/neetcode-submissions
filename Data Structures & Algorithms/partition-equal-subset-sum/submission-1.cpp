class Solution {
public:
    bool canPartition(vector<int>& nums) {

        int sum = 0;

        for(auto num : nums)
            sum += num;
        
        if(sum % 2 != 0)
            return false;

        int target = sum / 2;

        vector<vector<bool>> dp(nums.size(), vector<bool>(target+1,0));

        for(int i = 0; i < dp.size(); i++)
            dp[i][0] = true;

        if (nums[0] <= target)
            dp[0][nums[0]] = true;

        for(int i = 1; i < nums.size(); i++)
        {
            for(int j = 1; j <= target; j++)
            {
                bool nottake = dp[i-1][j];
                bool take = false;
                if(nums[i] <= j)
                        take = dp[i-1][j-nums[i]];
                dp[i][j] = take || nottake;
            }
        }

        return dp[nums.size()-1][sum/2];
    }
};
