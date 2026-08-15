class Solution {
public:
    bool isHappy(int n) {

        unordered_map<int, bool> seen;
        int output = n;
        seen[n] = true;
        while(output)
            {
                output = sumofSquare(output);
                if(seen[output] == true)
                    break;
                else
                    seen[output] = true;
            }
            
        
        if(output==1)
            return true;
        else
            return false;

    }

    int sumofSquare(int n)
    {
        int output = 0;
        while (n!=0)
        {
            output += (n % 10) * (n % 10);
            n = n/10;
        }

        return output;
    }
};
