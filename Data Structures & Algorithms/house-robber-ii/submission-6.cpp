class Solution {

public:
    int rob(vector<int>& nums) {
        vector<int> cache1, cache2;
        if(nums.size()==0)
            return 0;
        else if(nums.size()==1)
            return nums[0];
        int n = nums.size();
        cache1.resize(n, -1);
        cache2.resize(n, -1);
        return max(dfs(nums, 0, n-2, cache1), dfs(nums, 1, n-1, cache2));
    }

    int dfs(vector<int>& nums, int l, int r, vector<int>& cache)
    {
        
        if(l > r)
            return 0;
        
        if(cache[l] != -1)
            return cache[l];
        
        return cache[l] = max(dfs(nums, l+1, r, cache), nums[l]+dfs(nums,l+2,r, cache));
    }   
};
