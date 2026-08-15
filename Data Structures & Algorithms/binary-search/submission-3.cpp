class Solution {
public:
    int search(vector<int>& nums, int target) {
        int end = nums.size()-1;
        int beg = 0;
        int mid = end/2;
        while(beg <= end)
        {
            mid = beg + ((end - beg)/2);
            if(nums[mid] < target)
                {
                    beg = mid+1;
                }
            if(nums[mid] > target)
                {
                    end = mid-1;
                }
            if(nums[mid] == target)
                return mid;
            
        }
        return -1;
    }
};
