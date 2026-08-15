class Solution {
public:
    int findMin(vector<int> &nums) {
        int beg = 0;
        int end = nums.size()-1;

        int mid = (beg + end)/2;
        
        while(beg < end)
        {
            if(nums[mid] > nums[end])
            {
                beg = mid + 1;
            }

            else
            {
                end = mid;
            }

            mid = (beg + end) / 2;
        }

        return nums[beg];
    }
};
