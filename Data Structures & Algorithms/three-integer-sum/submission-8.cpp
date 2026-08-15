class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<int> pair;
        vector<vector<int>> soln;
        unordered_map<int,int> map;
        unordered_set<string> set;
        string used;

        sort(nums.begin(), nums.end());

        for(int i=0; i < nums.size(); i++)
        {
            if(i>0)
                if(nums[i]==nums[i-1])
                    continue;
            
            int a = nums[i];
            for(int j = i+1; j < nums.size(); j++)
            {
                if(map[0-(a+nums[j])] != 0)
                    {
                        used = to_string(a)+to_string(nums[j])+to_string(0-(a+nums[j]));
                        if(set.find(used) == set.end())
                        {
                            pair.push_back(a);
                            pair.push_back(nums[j]);
                            pair.push_back(0-(a+nums[j]));
                            set.insert(used);
                            soln.push_back(pair);
                            pair.clear();
                        }
                    }
                else
                {
                    map[nums[j]]++;
                }
            }

            map.clear();
                
        }

        return soln;
    }
};
