class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
        int i = 0;
        int maxp = 0;

        for(int j = i + 1; j < prices.size(); j++)
        {
            if(prices[j] > prices[i])
            {
                int profit = prices[j] - prices[i];
                maxp = max(maxp, profit);
            }

            else
            {
                i = j;
            }
        }

        return maxp;
    }
};
