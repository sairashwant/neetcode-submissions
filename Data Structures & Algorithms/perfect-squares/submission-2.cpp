class Solution {
public:
    unordered_map<int, int> memo;

    int numSquares(int n) {

        if(n == 0)
            return 0;

        if(memo.find(n) != memo.end()) return memo[n];

        int count = n;

        for(int i = 1; i * i <= n; i++)
        {
            count = min(count, 1 + numSquares(n - (i*i)));
            
        }

        return memo[n]=count;
    }
};