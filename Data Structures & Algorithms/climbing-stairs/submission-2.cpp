class Solution {
    vector<int> cache;
public:
    int climbStairs(int n) {

        cache.resize(n, -1);
        return climb(n, 0);
    }

    int climb(int n, int i)
    {
        if(i > n)
            return 0;

        if(i == n)
            return 1;

        if(cache[i]!=-1)    return cache[i];

        return cache[i]=climb(n, i+1) + climb(n, i+2);
    }
};
