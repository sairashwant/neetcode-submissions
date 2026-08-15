class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> product;
        float pdt = 1;
        int zerocount = 0;
        for(auto& num : nums)
        {
            if(num != 0)
                pdt *= num;
            
            else if(num == 0)
                zerocount++;
        }

        if (zerocount > 1) {
            return vector<int>(nums.size(), 0);
        }

        for(auto& num : nums)
        {
            if(zerocount > 0)
            {
                if(num != 0)
                    product.push_back(0);
                else if (num == 0)
                    product.push_back(pdt);
            }
            else
            {
                product.push_back(pdt/num);
            }
            
        }

        return product;
    }
};
