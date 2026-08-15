class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        
        unordered_map<char, int> count1;
        

        for(auto ch : s1)
        {
            count1[ch]++;
        }

        int need = count1.size();

        for(int i = 0; i < s2.length(); i++)
        {
            unordered_map<char, int> count2;
            int curr = 0;

            for(int j = i; j < s2.length(); j++)
            {
                char ch = s2[j];

                count2[ch]++;
                
                if(count1[ch] < count2[ch])
                    break;
                
                if(count1[ch] == count2[ch])
                    curr++;

                if(curr == need)
                    return true;
            }
        }
        return false;
    }
};
