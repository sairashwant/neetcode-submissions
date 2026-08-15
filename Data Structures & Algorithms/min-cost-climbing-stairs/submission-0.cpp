class Solution {
    vector<int> cache;
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        cache.resize(n, -1);
        return min(dfs(cost, 0), dfs(cost, 1));
    }

    int dfs(vector<int>& cost, int i)
    {
        int n = cost.size();

        if(i >= n)
            return 0;
        
        if(cache[i] != -1)
            return cache[i];

        int take1 = dfs(cost, i+1);
        int take2 = dfs(cost, i+2);

        return cache[i] = cost[i] + min(take1 , take2);
    }
};
