class Solution {
public:
    int maxProfit(vector<int>& prices) {

        int buy = 1;
        int profit = bfs(prices, 0, buy);
        return profit;
    }

    int bfs(vector<int>& prices, int i, int buy)
    {
        if(i >= prices.size())
            return 0;

        int profit = 0;

        if(buy)
            profit = max(-prices[i] + bfs(prices, i+1, 0), 0 + bfs(prices, i+1, 1));
        
        else
            profit = max(prices[i] + bfs(prices, i+2, 1), 0 + bfs(prices, i+1, 0));
        
        return profit;
    }
};
