class Solution {
public:
    int search(vector<int>& nums, int target) {
        int beg = 0;
        int end = nums.size()-1;
        while(beg < end)
        {
            int mid = (beg + end)/2;
            if(nums[mid] == target)
                return mid;

            if(nums[mid] > nums[end])
                beg = mid + 1;

            else
                end = mid; 
        }

        int pivot = beg;
        if(nums[end] <= target && target <= nums[nums.size()-1])
            {
                beg = pivot;
                end = nums.size()-1;
            }
        
        else
            {
                end = pivot-1;
                beg = 0;
            }

        while(beg <= end)
        {
            int mid = (beg + end)/2;
            if(nums[mid] == target)
                return mid;

            if(nums[mid] < target)
                beg = mid+1;
            
            else
                end = mid-1;
        }

        return -1;
    }
};
