class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        
        int globalMax = nums[0], globalMin = nums[0], currMax = 0, currMin = 0, total = 0;

        for(int num : nums)
        {
            currMax = max(currMax + num, num);
            globalMax = max(currMax, globalMax);
            currMin = min(currMin + num, num);
            globalMin = min(currMin, globalMin);
            total = total + num;
        }

        return globalMax > 0 ? max(globalMax, total - globalMin) : globalMax;
    }
};