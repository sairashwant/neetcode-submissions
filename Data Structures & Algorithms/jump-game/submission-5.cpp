class Solution {
public:
    bool canJump(vector<int>& nums) {
        
        int sum = 0;
        int size = nums.size();

        if(size <= 1)
            return true;

        int farthest = 0;
        for(int i=0 ; i <= size; i++)
        {
            if(i>farthest) 
                return false;

            farthest = max(i+nums[i], farthest);
            if(farthest >= size-1)
                return true;
        }
        return false;
    }
};
