class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        
        unordered_set<string> wordSet;
        int maxLen = 0;

        for(auto word : wordDict)
        {
            maxLen = max(maxLen, (int) word.length());
            wordSet.insert(word);
        }

        vector<int> dp(s.length()+1, false);
        string temp = "";

        dp[0] = true;


        for(int i=1; i <= s.length(); i++)
        {
            for(int j=i-1; j>=max(0, i-maxLen); j--)
            {
                if(dp[j] && wordSet.find(s.substr(j, i-j)) != wordSet.end())
                    {
                        dp[i]=true;
                        break;
                    }
            }
        }

        return dp[s.length()];
    }
};
