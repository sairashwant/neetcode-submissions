class Solution {
public:

    vector<int> dp;
    
    bool canReach(string s, int minJump, int maxJump) {
    
        dp.resize(s.length(), -1);
        if(bfs(s, 0, minJump, maxJump))
            return true;
        else
            return false;        
    }

    int bfs(string s, int i, int minJump, int maxJump)
    {
        int n = s.length();

        if(i == n-1)
            return true;

        if(dp[i] != -1) return dp[i];

        int start = i + minJump;
        int end = min(i + maxJump, n-1);

        for(int jump = start; jump <= end; jump++)
        {
            if(s[jump] == '0')
                {
                    bool result = bfs(s, jump, minJump, maxJump);
                    if(result) return dp[i] = true;
                }
        }

        return dp[i] = false;
    }
};