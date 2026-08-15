class Solution {
public:
    int maxProfit(vector<int>& prices) {

       int i = 0;
       int j = i+1;
       int maxp = 0;
       while(j < prices.size())
       {
            if(prices[i] < prices[j])
            {
                int profit = prices[j] - prices[i];
                maxp = max(maxp, profit);
            }
            else
            {
                i = j;
            }
            j++;
       } 
       return maxp;
    }
};
