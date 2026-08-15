class Solution {

    vector<int> cache;
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        cache.resize(n, -1);
        return dfs(nums, 0); 
    }

    int dfs(vector<int>& nums, int i)
    {
        int n = nums.size();
        
        if( i >= n)
            return 0;
        
        if(cache[i] != -1)
            return cache[i];
        
        cache[i] = max(dfs(nums,i+1), nums[i] + dfs(nums, i + 2));

        return cache[i];
    }
};
