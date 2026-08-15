class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        
        vector<vector<pair<int,int>>> adj(n);
        
        for(auto flight : flights)
        {
            adj[flight[0]].push_back({flight[1],flight[2]});
        }

        vector<vector<int>> dist(n, vector<int>(k+2, INT_MAX));

        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> minHeap;

        minHeap.emplace(0, src, 0);
        dist[src][0] = 0;
        
        while(!minHeap.empty())
        {
            auto [cost, node, stops] = minHeap.top();
            minHeap.pop();

            if(node == dst) return cost;
            if(stops == k+1) continue;
            if(cost > dist[node][stops]) continue;

            for(auto nei : adj[node])
            {
                auto nextStop = nei.first;
                auto nextCost = nei.second;
                if(dist[nextStop][stops+1] > cost + nextCost && stops+1 <= k+1)
                {
                    dist[nextStop][stops+1] = cost + nextCost;
                    minHeap.emplace(cost + nextCost, nextStop, stops+1);
                }
            }
        }
        return -1;
    }
};
