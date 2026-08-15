class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int i = 0, j = numbers.size()-1;
        vector<int> soln;
        while( i < j)
        {
            if(numbers[i] + numbers[j] > target)
            {
                j--;
            }

            else if(numbers[i] + numbers[j] < target)
            {
                i++;
            }

            else if(numbers[i] + numbers[j] == target)
            {
                soln.push_back(i+1);
                soln.push_back(j+1);
                return soln;
            }


        }

        return soln;

    }
};
