class Solution {
public:
    string multiply(string num1, string num2) {
        long long value1 = 0;
        long long value2 = 0;
        for(int i = 0; i < num1.size(); i++)
        {
            value1 = value1*10 + (int)(num1[i]-'0');
        }
        for(int i = 0; i < num2.size(); i++)
        {
            value2 = value2 * 10 + (int)(num2[i]-'0');
        }
        
        long long pdt = value1 * value2;

        if(num1 == "0" || num2 == "0")
            return "0";
        string num3;
        while(pdt)
        {
            num3 =  (char)(pdt%10 + '0') + num3;
            pdt = pdt/10;
        }

        return num3;
    }
};
