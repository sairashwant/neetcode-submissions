class Solution {
public:
    string longestPalindrome(string s) {
        string res = "";
        int resLen = 0;

        for(int i=0; i < s.length(); i++)
        {
            int l = i;
            int r = i;

            while(s[l]==s[r] && l>=0 && r<s.length())
            {
                if(r-l+1 > resLen)
                {   
                    resLen = r - l + 1;
                    res = s.substr(l, r-l+1);
                }
                l = l-1;
                r = r+1;
            }

            l = i;
            r = i+1; 
            while(s[l]==s[r] && l>=0 && r<s.length())
            {
                if(r - l + 1 > resLen)
                {
                    resLen = r - l + 1;
                    res = s.substr(l, r-l+1);
                }
                l = l-1;
                r = r+1;
            }           
        }

        return res;
    }
};
