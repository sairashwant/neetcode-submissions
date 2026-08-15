class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        
        vector<int> indegree(numCourses, 0);
        vector<vector<int>> adj(numCourses);

        for(auto edge : prerequisites)
        {
            adj[edge[1]].push_back(edge[0]);
            indegree[edge[0]]++;
        }

        queue<int> q;
        unordered_set<int> visited;
        
        for(int i = 0; i < indegree.size(); i++)
        {
            if(indegree[i] == 0)
                q.push(i);
        }

        vector<int> route;
        int prev;
        while(!q.empty())
        {
            int vertex = q.front();
            prev = vertex;
            q.pop();
            route.push_back(vertex);
            for(auto nei : adj[vertex])
            {
                
                    indegree[nei]--;

                    if(indegree[nei] == 0)
                        {
                            q.push(nei);
                        }                    
                
            }
        }
         if(route.size() == numCourses)
            return route;

        else
            return {};
    }
};
