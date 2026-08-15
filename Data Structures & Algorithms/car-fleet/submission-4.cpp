class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        
        int n = position.size();

        vector<pair<int,int>> speedPostion;
        int fleet = 1;

        for(int i = 0; i < n; i++)
        {
            speedPostion.push_back({position[i], speed[i]});
        }

        sort(speedPostion.begin(), speedPostion.end());

        double initialTime = (double) (target-speedPostion[n-1].first)/(double) speedPostion[n-1].second;

        for(int i = n-2; i >= 0; i--)
        {
            double carTime = (double)(target-speedPostion[i].first)/(double)speedPostion[i].second;
            if(carTime > initialTime)
                {
                    fleet++;
                    initialTime = carTime;
                }
            else continue;
        }

        return fleet;
    }
};
