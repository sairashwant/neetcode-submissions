class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        
        int n = nums.size()/3;
        unordered_map<int, int> count;
        
        for(auto num : nums)
        {
            count[num]++;
        }

        vector<int> result;

        for(auto num : count)
        {
            if(n < num.second)
            {
                result.push_back(num.first);
            }
        }

        return result;
    }
};