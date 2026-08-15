class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        
        int max = accumulate(weights.begin(), weights.end(), 0);
        
        int l = *max_element(weights.begin(), weights.end());
        int r = max;
        int result = INT_MAX;

        while(l <= r)
        {
            int cap = (l + r)/2;
            int d = 0;

            if(canShip(weights, days, cap))
            {
                result = min(result, cap);
                r = cap - 1;
            }

            else
            {
                l = cap + 1;
            }
        }

        return result;
    }

    bool canShip(vector<int>& weights, int days, int cap)
    {
        int ships = 1; int currCap = cap;

        for(auto weight : weights)
        {
            if(currCap - weight < 0)
                {
                    ships++;
                    if(ships > days)
                        return false;
                    
                    currCap = cap;
                }

                currCap -= weight;
        }

        return true;
    }
};