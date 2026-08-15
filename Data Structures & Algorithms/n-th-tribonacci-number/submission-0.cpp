class Solution {
public:

    vector<int> dp;

    int tribonacci(int n) {

        dp.resize(n+1, -1);
        dp[0] = 0;
        dp[1] = 1;
        dp[2] = 1;
        int out = tribomemo(n, dp);
        return out;
    }

    int tribomemo(int n, vector<int> &dp)
    {
        if(n < 0)
            return 0;

        if(dp[n] != -1) return dp[n];

        dp[n] = tribomemo(n-1, dp) + tribomemo(n-2, dp) + tribomemo(n-3, dp);
        return dp[n];
    }
};