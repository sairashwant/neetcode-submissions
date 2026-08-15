class Solution {
public:
    bool checkValidString(string s) {
        
        int n = s.length();
        vector<vector<int>> dp(n+1, vector<int>(n+1, -1));
        return f(s, 0, 0, dp);   
    }

    bool f(string s, int i, int count, vector<vector<int>> &dp)
    {
        bool ans = false; 

        if(i >= s.length())
            return count == 0;
        
        if(count < 0)
            return false;

        if(dp[i][count] != -1)  return dp[i][count];

        if(s[i] == '(')
            ans = f(s, i+1, count+1, dp);
        
        if(s[i] == ')')
            ans = f(s, i+1, count-1, dp);

        if(s[i] == '*')
            ans = f(s, i+1, count+1, dp) || f(s, i+1, count-1, dp) || f(s, i+1, count, dp);

        return dp[i][count] = ans;
    }
};