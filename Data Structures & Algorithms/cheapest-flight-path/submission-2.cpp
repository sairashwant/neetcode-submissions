class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int,int>>> adj(n);
        for (auto &f : flights)
            adj[f[0]].emplace_back(f[1], f[2]);

        // dist[node][s] = min cost to reach node using exactly s flights (0..k)
        const int INF = INT_MAX / 2;
        vector<vector<int>> dist(n, vector<int>(k+1 + 1, INF)); // allow 0..k flights, keep size k+1
        dist[src][0] = 0;

        // min-heap: (cost, node, flightsUsed)
        using T = tuple<int,int,int>;
        priority_queue<T, vector<T>, greater<T>> pq;
        pq.emplace(0, src, 0);

        while (!pq.empty()) {
            auto [cost, node, used] = pq.top(); pq.pop();
            if (node == dst) return cost;                     // first time popped is cheapest for valid used
            if (used == k+1) continue;                        // used is number of nodes or flights? we use flights count
            // if this state is stale wrt dist:
            if (cost > dist[node][used]) continue;

            for (auto &e : adj[node]) {
                int nei = e.first, w = e.second;
                int nextUsed = used + 1;
                if (nextUsed <= k+1 && dist[nei][nextUsed] > cost + w) {
                    dist[nei][nextUsed] = cost + w;
                    pq.emplace(dist[nei][nextUsed], nei, nextUsed);
                }
            }
        }
        return -1;
    }
};
