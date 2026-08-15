class Solution {
public:

    string encode(vector<string>& strs) {
        
        if(strs.size() == 0)
            {
                string result = "";

                return result;
            }
        string result = to_string(strs[0].length()) + '#' + strs[0];

        for(int i=1; i < strs.size(); i++)
        {
            result += to_string(strs[i].length()) + '#' + strs[i];
        }
        return result;
    }

    vector<string> decode(string s) {

        vector<string> result;

        int i = 0;

        while(i < s.size())
        {
            int j = i;
            while(s[j] != '#')
            {
                j++;
            }
                int len = stoi(s.substr(i,j-i));

                i= j + 1;
                j = i + len;
                result.push_back(s.substr(i, len));
                i=j; 
            }

            return result;
        }

};
