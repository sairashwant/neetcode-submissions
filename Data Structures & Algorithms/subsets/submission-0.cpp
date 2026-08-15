class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        
        vector<vector<int>> resultset;
        vector<int> temp;
        
        subset(nums, temp, resultset, 0);  
        return resultset;
    }

    void subset(vector<int> nums, vector<int> &temp, vector<vector<int>> &resultset, int start)
    {
        if( start >= nums.size())
        {
            resultset.push_back(temp);
            return;
        }

        temp.push_back(nums[start]);
        subset(nums, temp, resultset, start+1);
        temp.pop_back();
        subset(nums, temp, resultset, start+1);
    }
};
