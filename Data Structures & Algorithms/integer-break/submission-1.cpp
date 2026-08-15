class Solution {
public:

    vector<vector<int>> dp;
    int integerBreak(int n) {
      
      dp.resize(n+1, vector<int>(n+1,-1));
      return integerbreak(n, n-1);  
    }

    int integerbreak(int num, int i)
    {
        if(min(num, i) < 1) return 1;

        if(i > num) return integerbreak(num, num);

        if(dp[num][i] != -1) return dp[num][i];

        return dp[num][i]=max(i * integerbreak(num-i, i), integerbreak(num, i-1));
    }
};