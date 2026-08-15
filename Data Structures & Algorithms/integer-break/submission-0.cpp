class Solution {
public:
    int integerBreak(int n) {

      return integerbreak(n, n-1);  
    }

    int integerbreak(int num, int i)
    {
        if(min(num, i) < 1) return 1;

        if(i > num) return integerbreak(num, num);

        return max(i * integerbreak(num-i, i), integerbreak(num, i-1));
    }
};