class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> stk;
        

        for(int i = 0; i < asteroids.size(); i++)
        {
            bool destroyed = false;

            while(!stk.empty() && stk.top() > 0 && asteroids[i] < 0)
            {
                int stone1 = stk.top();
                int stone2 = asteroids[i];
                
                if(abs(stone1) < abs(stone2))
                {
                    stk.pop();
                    continue;
                }
                
                if(abs(stone1) == abs(stone2))
                {
                    stk.pop();
                    destroyed = true;
                    break;
                }

                if(abs(stone1) > abs(stone2))
                {
                    destroyed = true;
                    break;
                }
            }
            if(!destroyed)
                {
                    stk.push(asteroids[i]);
                }
        }

        vector<int> result;
        
        while(!stk.empty())
        {
            result.push_back(stk.top());
            stk.pop();
        }
        reverse(result.begin(), result.end());
        return result;
    }
};