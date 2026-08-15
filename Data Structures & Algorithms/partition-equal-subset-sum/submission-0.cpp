class Solution {
public:

    bool f(vector<int>& nums, int index, int target)
    {
        if(target == 0) return true;

        if(index < 0) return false;
        if(index == 0) return nums[0]==target;

        bool nottake = f(nums, index-1, target);
        bool take = false;
        if(nums[index] <= target)
            take = f(nums, index-1, target-nums[index]);

        return take || nottake;
    }

    bool canPartition(vector<int>& nums) {
        
        int sum = 0;

        for(auto num : nums)
            sum = sum + num;

        if(sum%2 != 0)
            return false;

        return f(nums, nums.size()-1,sum/2);
    }
};
