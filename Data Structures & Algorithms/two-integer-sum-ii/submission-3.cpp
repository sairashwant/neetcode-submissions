class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        
        int i = 0, j = numbers.size()-1, sum = 0;
        vector<int> results;

        while(i < j)
        {
            int tempSum = numbers[i] + numbers[j];
            
            if(tempSum > target)
            {
                j--;
            }

            if(tempSum < target)
            {
                i++;
            }

            if(tempSum == target)
            {
                results.push_back(i + 1);
                results.push_back(j + 1);
                return results;
            }
        }    
    }
};
