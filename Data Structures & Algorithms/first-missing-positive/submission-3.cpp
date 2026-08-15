class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        
        
        unordered_set<int> temp;
        int maxVal = 0;

        for(int i = 0; i < nums.size(); i++)
        {
            temp.insert(nums[i]);
            maxVal = max(nums[i], maxVal);
        }

        for(int i = 1; i <= maxVal; i++)
        {
            if(temp.find(i) == temp.end())
                return i;
        }
        return maxVal+1;
    }
};