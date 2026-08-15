class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int maxpdt = nums[0];
        int currMax = 1; int currMin=1;
        for(int num : nums)
        {
            int pdt = currMax * num;
            currMax = max(max(num*currMin,pdt),num);
            currMin = min(min(num*currMin,pdt),num);
            maxpdt = max(maxpdt, currMax);
        }

        return maxpdt;
    }
};
