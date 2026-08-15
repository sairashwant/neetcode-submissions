class Solution {
public:
    int countSubstrings(string s) {
        int n = s.length();
        int resCount = 0;
        for(int i=0; i<n; i++)
        {
            int l = i;
            int r = i;
            while(l >= 0 && r < n && s[l]==s[r])
            {
                resCount++;
                l = l-1;
                r = r+1;
            }

            l = i;
            r = i+1;
            while(l >= 0 && r < n && s[l]==s[r])
            {
                resCount++;
                l = l-1;
                r = r+1;
            }
        }
        return resCount;
    }
};
