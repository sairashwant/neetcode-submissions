class Solution {
public:
    void sortColors(vector<int>& nums) {
        for(int i = 0; i < nums.size(); i++)
        {
            for(int j = i+1; j <= nums.size()-1; j++)
            {
                if(nums[i] > nums[j])
                    swap(nums[i], nums[j]);
            }
        }
    }
};