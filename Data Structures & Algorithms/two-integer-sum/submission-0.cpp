class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int, int> hashmap;
        vector<int> sol;
        for(int i=0; i < nums.size(); i++)
        {
            auto it = hashmap.find(target - nums[i]);
            if(it == hashmap.end())
            {
                if(hashmap.find(nums[i]) == hashmap.end())
                    hashmap[nums[i]] = i;
            } 
            else
            {
                sol.push_back(it -> second);
                sol.push_back(i);
                return sol;
            }
        }
        return sol;
    }
};
