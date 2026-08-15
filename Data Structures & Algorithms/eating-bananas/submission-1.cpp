class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        
        int start = 1;
        int end = *max_element(piles.begin(), piles.end());

        while(start < end)
        {
            int mid = (start + end) / 2;

            double total = 0;

            for(int pile : piles)
            {
                total += ceil((double)pile/mid);
            }

            if(total <= h)
            {
                end = mid;
            }

            else
            {
                start = mid + 1;
            }
        }

        return start;
    }
};
