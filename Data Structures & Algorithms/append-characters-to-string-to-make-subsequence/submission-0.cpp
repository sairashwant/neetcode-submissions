class Solution {
public:
    int appendCharacters(string s, string t) {
        
        int ptr = 0;

        for(int i = 0; i < s.length(); i++)
        {
            if(s[i] == t[ptr])
                ptr++;
            
            else
                continue;
        }

        return (t.length() - ptr);
    }
};