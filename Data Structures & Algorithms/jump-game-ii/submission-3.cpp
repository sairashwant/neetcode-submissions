class Solution {
public:
    int jump(vector<int>& nums) {
        return f(nums, 0);
    }

    int f(vector<int> nums, int i)
    {
        int ans = INT_MAX;

        if(i>=nums.size() - 1)
            return 0;

        for(int jump = 1; jump <= nums[i]; jump++)
        {
            int next = f(nums, i+jump);
            if(next != INT_MAX)
                ans = min(ans, 1 + next);
        }

        return ans;

    }
};
