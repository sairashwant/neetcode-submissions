class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        vector<int> temp;
        unordered_set<string> set;
        sort(candidates.begin(), candidates.end());
        string str="";
        backtrack(candidates, temp, result, target, 0, set, str);
        return result;
    }

    void backtrack(vector<int> candidates,vector<int> temp, vector<vector<int>> &result, int target, int start, unordered_set<string> set, string str)
    {
        if(target == 0)
        {
            if(set.find(str)==set.end())
                {
                    set.insert(str);
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
            str = str + to_string(candidates[i]);
            backtrack(candidates, temp, result, target-candidates[i], i+1, set ,str);
            temp.pop_back();
            str.erase(str.length()-1);
        }
    }
};
