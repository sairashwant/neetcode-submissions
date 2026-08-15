class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        
        unordered_map<char, int> lastseen;

        int count = 0, maxcount = 0, start = 0;

        for(int i = 0; i < s.length(); i++)
        {
            char c = s[i];
            auto seenindex = lastseen.find(c);

            if(seenindex != lastseen.end() && seenindex->second >= start)
            {
                start = seenindex->second+1;
            }
            
            lastseen[c] = i;
            count++;
            maxcount = max(i - start + 1, maxcount);
        }
        
        return maxcount;
    }
};
