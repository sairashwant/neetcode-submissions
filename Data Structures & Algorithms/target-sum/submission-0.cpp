class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        
        int ways = 0;
        ways = bfs(nums, target, 0, ways, 0);
        return ways;
    }

    int bfs(vector<int>& nums, int target, int i, int count, int sum)
    {
        if(i >= nums.size())
            return sum == target ? 1 : 0;
        
        int add = bfs(nums, target, i+1, count, sum + nums[i]);
        int diff = bfs(nums, target, i+1, count, sum - nums[i]);

        return add + diff;
    }
};
