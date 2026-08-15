class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> temp;
        unordered_set<string> keyset;
        string key="";
        sort(nums.begin(), nums.end());
        dfs(nums, result, temp, key, keyset, 0);
        return result;
    }

    void dfs(vector<int> &nums, vector<vector<int>> &result, vector<int> temp, string key, unordered_set<string> &key_set, int start)
    {
        if(start >= nums.size())
        {
            cout<<key<<endl;
            if(key_set.find(key) == key_set.end())
                {
                    key_set.insert(key);
                    result.push_back(temp);
                }
            return;
        }

        temp.push_back(nums[start]);
        int prevlen = key.length();
        key = key + to_string(nums[start]) + ',';
        dfs(nums, result, temp, key, key_set, start+1);
        key.erase(prevlen);
        temp.pop_back();
        dfs(nums, result, temp, key, key_set, start+1);

    }
};
