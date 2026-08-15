class Solution {
public:
    int countComponents(int n, vector<vector<int>>& edges) {

        vector<vector<int>> adj(n);
        unordered_set<int> visited;
        int count = 0;
        for(auto edge : edges)
        {
            adj[edge[0]].push_back(edge[1]); 
            adj[edge[1]].push_back(edge[0]); 
        }

        for(int i = 0; i < n; i++)
        {
            if(visited.find(i) == visited.end())
            {
                count++;
                visited.insert(i);
                bfs(edges, adj, n, i, visited);
            }
        }

        return count;
    }

    void bfs(vector<vector<int>>& edges, vector<vector<int>> adj, int n, int i, unordered_set<int> &visited)
    {
        queue<int> q;
        q.push(i);
        
        while(!q.empty())
        {
            int val = q.front();
            q.pop();
            for(auto nei : adj[val])
            {
                if(visited.find(nei) == visited.end())
                {
                    visited.insert(nei);
                    q.push(nei);
                }
            }
        }
    }
};
