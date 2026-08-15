class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        vector<int> temp;
        unordered_map<string, int> map;
        sort(candidates.begin(), candidates.end());
        string str="";
        backtrack(candidates, temp, result, target, 0, map, str);
        return result;
    }

    void backtrack(vector<int> candidates,vector<int> temp, vector<vector<int>> &result, int target, int start, unordered_map<string, int> map, string str)
    {
        if(target == 0)
        {
            if(map[str]==0)
                {
                    sort(temp.begin(), temp.end());
                    if(find(result.begin(), result.end(), temp) == result.end())
                        result.push_back(temp);
                    return;
                }
        }

        for(int i = start; i < candidates.size(); i++)
        {
            if(candidates[i] > target)
                break;
            if(start > i && candidates[i]==candidates[i-1])
                continue;
            temp.push_back(candidates[i]);
            backtrack(candidates, temp, result, target-candidates[i], i+1, map ,str);
            temp.pop_back();
        }
    }
};
