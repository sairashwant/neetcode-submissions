class Solution {
public:

    vector<int> dp;

    int minCostClimbingStairs(vector<int>& cost) {
        dp.resize(cost.size(), -1); 
        return min(climb(cost, 0), 
        climb(cost, 1));
    }

    int climb(vector<int> cost, int step)
    {
        if(step >= cost.size())
            return 0;
        
        if(step == cost.size()-1)
        {
            return cost[cost.size() - 1];
        }

        if(dp[step] != -1)
            return dp[step];

        return dp[step] = cost[step] + 
        min(climb(cost, step + 1), 
        climb(cost, step + 2));
    }
};
