class Solution {
public:
    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        
        vector<unordered_set<int>> adj(numCourses);
        vector<unordered_set<int>> isPreReq(numCourses);
        vector<int> indegree(numCourses, 0);

        for(auto pre : prerequisites)
        {
            adj[pre[0]].insert(pre[1]);
            indegree[pre[1]]++;
        }

        queue<int> q;
        
        for(int i = 0; i < numCourses; i++)
        {
            if (indegree[i] == 0)
                q.push(i);
        }

        while(!q.empty())
        {
            int node = q.front();
            q.pop();

            for(int nei : adj[node])
            {
                isPreReq[nei].insert(node);
                isPreReq[nei].insert(isPreReq[node].begin(), isPreReq[node].end());
                indegree[nei]--;

                if(indegree[nei] == 0)
                    q.push(nei);
            }
        }

        vector<bool> result;
        for(auto query : queries)
        {
            result.push_back(isPreReq[query[1]].count(query[0]));
        }

        return result;
    }
};