class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char, int> hashMap1;
        unordered_map<char, int> hashMap2;

        if(s.length() != t.length())
            return false;

        for(auto ch : s)
        {
            hashMap1[ch]++;
        }

        for(auto ch : t)
        {
            hashMap2[ch]++;
        }
        
        return hashMap1 == hashMap2;
    }
};
