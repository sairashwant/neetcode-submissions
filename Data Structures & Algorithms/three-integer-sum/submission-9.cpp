class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<int> partialResult;
        vector<vector<int>> result;
        unordered_map<int, int> hashMap;
        unordered_set<string> set;

        sort(nums.begin(), nums.end());

        for(int i = 0; i < nums.size(); i++)
        {
            int a = nums[i];
            for(int j = i+1; j < nums.size(); j++)
            {
                if(hashMap[0 - (a+nums[j])] != 0)
                {
                    string used = to_string(a) + to_string(nums[j]) + 
                    to_string(0-(a + nums[j]));

                    if(set.find(used) == set.end())
                    {
                        partialResult.push_back(a);
                        partialResult.push_back(nums[j]);
                        partialResult.push_back(0-(a + nums[j]));
                        set.insert(used);
                        result.push_back(partialResult);
                        partialResult.clear();
                    }
                }

                else

                hashMap[nums[j]]++;
            }

            hashMap.clear();
        }

        return result;
    }
};
