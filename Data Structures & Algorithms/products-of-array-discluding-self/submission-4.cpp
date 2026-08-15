class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        
        vector<int> pdt;

        int product = 1;
        int zeroPos = 0;

        for(auto num : nums)
        {
            if(num == 0)
                {
                    zeroPos++;
                    continue;
                }

            product = product * num;
            
        }

        for(int i = 0; i < nums.size(); i++)
        {
            if(zeroPos == nums.size())
                {
                    pdt.push_back(0);
                    continue;
                }

            if(zeroPos == 0)
                pdt.push_back(product / nums[i]);
            
            else if(zeroPos == 1)
                if(nums[i] != 0)
                    pdt.push_back(0);
                else
                    pdt.push_back(product);
            
            else
                pdt.push_back(0);
        }

        return pdt;
    }
};
