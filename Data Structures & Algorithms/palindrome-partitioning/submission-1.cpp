class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> result;
        vector<string> temp;
        int start = 0;
        backtrack(s, result, temp, start);
        return result;
    }

    void backtrack(string s, vector<vector<string>> &result, vector<string> temp, int start)
    {
        if(start >= s.length())
        {
            result.push_back(temp);
            return;
        }

        for(int i = start; i < s.length(); i++)
        {
            if(ispal(s, start, i))
                {
                    temp.push_back(s.substr(start, i-start+1));
                    backtrack(s, result, temp, i+1);
                    temp.pop_back();
                }
        }
    }

    bool ispal(string s, int start, int i)
    {
        while (start < i) {
            if (s[start++] != s[i--]) return false;
        }
        return true;
    }

};
