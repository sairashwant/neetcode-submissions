class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        
        unordered_map<string, vector<string>> hashMap;
        vector<vector<string>> result;

        for(auto str : strs)
        {
            string original = str;
            sort(str.begin(), str.end());
            hashMap[str].push_back(original);
        } 

        for(auto key : hashMap)
        {
            result.push_back(key.second);
        }

        return result;
    }
};
