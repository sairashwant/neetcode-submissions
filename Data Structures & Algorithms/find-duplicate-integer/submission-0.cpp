class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        vector<int> count(nums.size(), 0);
        for(int num : nums)
        {
            count[num]++;
        }
        for(int num : nums)
        {
            if(count[num]>1)
                return num;
        }
    }
};
