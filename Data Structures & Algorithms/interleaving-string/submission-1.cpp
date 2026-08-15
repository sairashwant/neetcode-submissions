class Solution {
public:

    bool isInterleave(string s1, string s2, string s3) {
        vector<vector<int>> memo(s1.length()+1, vector<int>(s2.length()+1, -1));
        return interleave(s1, s2, s3, 0, 0, 0, memo);
    }

    bool interleave(string s1, string s2, string s3, int i, int j, int k, vector<vector<int>> &memo)
    {
        if( k == s3.length() )
            return (i == s1.length()) && (j == s2.length());
        
        if(memo[i][j] != -1) return memo[i][j]==1;

        bool ok = false;

        if(s1[i] == s3[k] && i < s1.length())
        {
            ok = interleave(s1, s2, s3, i+1, j, k+1, memo);
        }  

        if(s2[j] == s3[k] && j < s2.length())
        {
            ok = interleave(s1, s2, s3, i, j+1, k+1, memo);
        }     

        memo[i][j] = ok? 1 : 0;
        return ok; 
    }
};
