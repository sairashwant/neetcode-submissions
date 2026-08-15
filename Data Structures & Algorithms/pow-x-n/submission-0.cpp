class Solution {
public:
    double myPow(double x, int n) {
              
        if(n < 0)
            {
                x = 1/x;
                n = -n;
            }
        double pdt =  x;
        double result = 1;

        while(n)
        {
            if(n % 2 == 1)
            {
                result = result * pdt;
            }
            pdt = pdt * pdt;
            n = n/2;
        }

        return result;
    }
};
