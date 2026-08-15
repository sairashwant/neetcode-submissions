class Solution {
public:
    int left = 0;
    int right = 0;
    int up = 0;
    int down = 0;

    bool makesquare(vector<int>& matchsticks) {

        int sum = accumulate(matchsticks.begin(), matchsticks.end(), 0);

        if (sum % 4 != 0) return false;

        sort(matchsticks.rbegin(), matchsticks.rend());

        return bfs(matchsticks, 0, sum/4);
    }

    bool bfs(vector<int>& matchsticks, int i, int target)
    {
        if(i >= matchsticks.size())
        {      
            if( left == right && right == up && up == down)      
                return true;

            return false;
        }
        

        left = left + matchsticks[i];
        if (target >= left && bfs(matchsticks, i+1, target)) return true;
        left = left - matchsticks[i];

        right = right + matchsticks[i];
        if (target >= right && bfs(matchsticks, i+1, target)) return true;
        right = right - matchsticks[i];

        up = up + matchsticks[i];
        if (target >= up && bfs(matchsticks, i+1, target)) return true;
        up = up - matchsticks[i];

        down = down + matchsticks[i];
        if (target >= down && bfs(matchsticks, i+1, target)) return true;
        down = down - matchsticks[i];

        return false;
    }
};