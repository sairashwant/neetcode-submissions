class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        
        vector<pair<int, int>> speedVector;
        int n = position.size();

        for(int i = 0; i < n; i++)
        {
            speedVector.emplace_back(position[i], speed[i]);
        }

        sort(speedVector.begin(), speedVector.end());

        int fleet = 1;

        double initialTime = (double)(target - speedVector[n-1].first) / (double)speedVector[n-1].second;

        for(int i = n-2; i >= 0; i--)
        {
            double carTime = (double)(target - speedVector[i].first) / 
            (double)speedVector[i].second;

            if(carTime > initialTime)
            {
                fleet++;
                initialTime = carTime;
            }
        }

        return fleet;
    }
};
