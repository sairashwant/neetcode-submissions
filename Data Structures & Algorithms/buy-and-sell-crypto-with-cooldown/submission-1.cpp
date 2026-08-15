class Solution {
public:
    int maxProfit(vector<int>& prices) {

        vector<vector<int>> dp(prices.size()+2, vector<int>(2, 0));
        int buy = 1;
        int profit = 0;

        for(int i = prices.size()-1; i >= 0; i--)
        {
            for(int buy = 0; buy <= 1; buy++)
            {
                if(buy)
                    profit = max(-prices[i] + dp[i+1][0], 0 + dp[i+1][1]);

                else
                    profit = max(prices[i] + dp[i+2][1], 0 + dp[i+1][0]);

                dp[i][buy] = profit;
            }
            
        }

        return dp[0][1];
    }

    int bfs(vector<int>& prices, int i, int buy)
    {
        if(i >= prices.size())
            return 0;

        int profit = 0;

        
        
        return profit;
    }
};
