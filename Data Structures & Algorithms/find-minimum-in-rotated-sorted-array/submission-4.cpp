class Solution {
public:
    int findMin(vector<int> &nums) {
        int end = nums.size()-1;
        int beg = 0;
        int mid = (beg + end)/2;
        while(beg < end)
        {
            if(nums[mid]>nums[end])
                beg = mid + 1;

            else if(nums[mid]<nums[end])
                end = mid;

            mid = beg+(end-beg)/2;
        }

        return nums[beg];
    }
};
