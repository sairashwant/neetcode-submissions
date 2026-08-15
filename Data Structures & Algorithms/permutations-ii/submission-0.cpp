class Solution {
public:

    set<vector<int>> result;

    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<int> prem;
        backtrack(nums, prem);
        return vector<vector<int>>(result.begin(), result.end());
    }

    void backtrack(vector<int> &nums, vector<int> &prem)
    {
        if(prem.size() == nums.size())
        {
            result.insert(prem);
            return;
        }

        for(int i = 0; i < nums.size(); i++)
        {
            if(nums[i] != INT_MIN)
            {
                int temp = nums[i];
                prem.push_back(temp);
                nums[i] = INT_MIN;
                backtrack(nums, prem);
                nums[i] = temp;
                prem.pop_back();
            }
        }
    }
};