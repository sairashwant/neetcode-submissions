class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        

        int l = 0;
        int r = 0;
        int len = INT_MAX;
        int sum = 0;
        
        while(r < nums.size())
        {
            sum = sum + nums[r];

            while(sum >= target)
                {
                    len = min(len, r-l+1);
                    sum = sum - nums[l];
                    l = l+1;
                }

            r++;
        }

        return len == INT_MAX ? 0 : len;
    }
};