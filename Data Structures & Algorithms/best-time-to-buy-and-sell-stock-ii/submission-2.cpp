class Solution {
public:

    vector<vector<int>> memo;

    int maxProfit(vector<int>& prices) {
        memo.resize(prices.size()+1, vector<int>(2, -1));
        return rec(prices, 0, 0);
    }

    int rec(vector<int>& prices, int i, int bought)
    {
        if(i == prices.size())
            return 0;

        int res = rec(prices, i+1, bought);

        if(memo[i][bought] != -1) return memo[i][bought];
        if(bought == 1)
        {
            res = max(res, prices[i] + rec(prices, i+1, 0));
        }
        else
        {
            res = max(res, -prices[i] + rec(prices, i+1, 1));
        }

        return memo[i][bought]=res;
    }
};