class Solution {
public:
    int change(int amount, vector<int>& coins) {
        
        vector<vector<int>> dp(coins.size()+1, vector<int>(amount+1, -1));
        sort(coins.begin(), coins.end());
        return dfs(coins, amount, dp, 0);
    }

    int dfs(vector<int>& coins, int amount, vector<vector<int>> &dp, int i)
    {
        if(amount == 0) return 1;
        if(i >= coins.size()) return 0;
        if(dp[i][amount] != -1) return dp[i][amount];

        int res = 0;
        
        if(amount >= coins[i])
        {
            res = dfs(coins, amount, dp, i+1);
            res = res+ dfs(coins, amount-coins[i], dp, i);
        }

        return dp[i][amount] = res;
    }
};
