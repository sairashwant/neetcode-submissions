class Solution {
public:
    vector<int> partitionLabels(string s) {
        
        unordered_map<char, int> map;
        vector<int> res;

        for(int i = 0; i < s.length(); i++)
        {
            map[s[i]] = i;
        }

        int end = 0;
        int size = 0;
        for(int i = 0; i < s.length(); i++)
        {
            size++;

            if(map[s[i]] > end)
                end = map[s[i]];

            if(i == end)
            {
                res.push_back(size);
                size = 0;
            }
        }
        return res;

    }
};
