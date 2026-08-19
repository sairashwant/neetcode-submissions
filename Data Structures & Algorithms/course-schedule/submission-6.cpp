class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        
        if(prerequisites.size() == 0)
        {
            return true;
        }

        vector<int> indegree(numCourses, 0);
        vector<vector<int>> adj(numCourses);

        for(auto edges : prerequisites)
        {
            adj[edges[1]].push_back(edges[0]);
            indegree[edges[0]]++;
        }

        queue<int> q;
        unordered_set<int> visited;

        for(int i = 0; i < indegree.size(); i++)
        {
            if(indegree[i] == 0)
            {
                q.push(i);
            }
        }

        while(!q.empty())
        {
            int vertex = q.front();
            
            q.pop();
            if(visited.find(vertex) == visited.end())
            {
                visited.insert(vertex);
            for(auto nei : adj[vertex])
            {
                indegree[nei]--;
                if(indegree[nei] == 0)
                    q.push(nei);
            }
        }
        }

        if(visited.size() == numCourses)
            return true;
        
        return false;
    }
};
