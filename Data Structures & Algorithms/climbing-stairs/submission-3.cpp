class Solution {
public:

    vector<int> cache;

    int climbStairs(int n) {
        
        cache.resize(n+1, -1);
        return dpclimbStairs(n);
    }

    int dpclimbStairs(int n)
    {
        if(n < 0)
            return 0;

        if(n == 0)
            return 1;
        
        if(cache[n] != -1)
            return cache[n];

        return cache[n] = (dpclimbStairs(n-1) + dpclimbStairs(n-2));
    }
};
