class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        
        int end = digits.size()-1;
        digits[end] += 1;
        int j = end;

        while(j>0)
        {
            if(digits[j] == 10)
                {
                    
                    digits[j] = 0;
                    digits[j-1] += 1; 
                }
            j--;
            
        }

        if(digits[j] == 10 && j == 0)
                {
                    digits[j] = 0;
                    digits.insert(digits.begin(),1);
                }

        return digits;
    }
};
