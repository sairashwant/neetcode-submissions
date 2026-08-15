class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        vector<int> rotatedNums(nums.size(), -1);

        for(int i = 0; i < nums.size(); i++)
        {
            rotatedNums[(k++ % nums.size())] = nums[i];
        }

        nums = rotatedNums;
    }
};