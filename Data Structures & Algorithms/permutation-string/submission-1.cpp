class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        
        unordered_map<char, int> count1;
        unordered_map<char, int> count2;

        int n1 = s1.length();
        int n2 = s2. length();

        if(n1 > n2)
            return false;

        for(char ch : s1)
        {
            count1[ch]++;
        }
        for(int i = 0; i < s2.length(); i++)
        {
            count2[s2[i]]++;

            if(i >= n1)
            {
                count2[s2[i - n1]]--;
                if(count2[s2[i - n1]] == 0)
                    count2.erase(s2[i - n1]);
            }

            if(count1 == count2)
            {
                return true;
            }
        }

        return false;
    }
};
