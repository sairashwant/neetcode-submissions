class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        
        auto compare = [&] (vector<int> a, vector<int> b){
            return a[1] < b[1];
        };

        sort(trips.begin(), trips.end(), compare);

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> minHeap; 
        int currPass = 0;

        for(auto trip : trips)
        {
            int numPass = trip[0]; int start = trip[1]; int end = trip[2];

            while(!minHeap.empty() && minHeap.top().first <= start)
            {
                currPass -= minHeap.top().second;
                minHeap.pop();
            }

            currPass += numPass;

            if(currPass > capacity)
                return false;

            minHeap.emplace(end, numPass);
        }

        return true;
    }
};