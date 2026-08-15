class Solution {

    vector<int> memo;
public:
    int rob(vector<int>& nums) {
        memo.resize(nums.size(), -1);
        return startrob(nums, 0);
    }

    int startrob(vector<int>& nums, int i)
    {
        if(i>=nums.size() || i < 0)
            return 0;

        if(memo[i] != -1)
            return memo[i];

        return memo[i] = max(nums[i]+startrob(nums, i+2), startrob(nums, i+1));
    }
};
