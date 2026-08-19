class Solution {
public:
    vector<int> partitionLabels(string s) {
       
       unordered_map<char, int> lastSeen;
       vector<int> res;

       for(int i = 0; i < s.length(); i++)
       {

        lastSeen[s[i]] = i;

       } 

       int end = 0;
       int start = 0;

       for(int i = 0; i < s.length(); i++)
       {
            end = max(end, lastSeen[s[i]]);
            
            if(i == end)
            {
                int result = end - start + 1;
                res.push_back(result);
                start = end + 1;
            }          
       }

       return res;
    }
};
