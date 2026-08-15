class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        
        int n = edges.size();

        vector<vector<int>> adj(n+1);
        vector<int> indegree(n+1);

        for(auto edge : edges)
        {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
            indegree[edge[0]]++;
            indegree[edge[1]]++;
        }

        queue<int> q;

        for(int i = 1; i <= n; i++)
        {
            if(indegree[i] == 1)
            {
                q.push(i);
            }
        }

        while(!q.empty())
        {
            auto vertex = q.front();
            q.pop();
            indegree[vertex]--;

            for(auto nei : adj[vertex])
            {
                indegree[nei]--;
                if(indegree[nei] == 1)
                    q.push(nei);
            }
        }
        for(int i = edges.size()-1; i >= 0; i--)
            {
                if(indegree[edges[i][0]] == 2 && indegree[edges[i][1]])
                    return {edges[i][0], edges[i][1]};
            }
        return {};
    }
};
