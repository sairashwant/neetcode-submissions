class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        
        unordered_map<int, vector<pair<int,int>>> edges;
        for(auto time : times)
        {
            edges[time[0]].emplace_back(time[1], time[2]);
        }

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> minheap;

        minheap.push({0, k});
        unordered_set<int> visited;

        int time = 0;

        while(!minheap.empty())
        {
            auto temp = minheap.top();
            minheap.pop();
            
            int w1 = temp.first;
            int n1 = temp.second;

            if(visited.find(n1) != visited.end()) continue;

            time = w1;
            visited.insert(n1);

            if(edges.find(n1) == edges.end()) continue;

            for(auto next : edges[n1])
            {
                int n2 = next.first;
                int w2 = next.second;
                if(visited.find(n2) == visited.end())
                {
                    minheap.push({w1+w2, n2});
                }
            }      
        }

        if(visited.size() == n)
            return time;

        else
            return -1;
    }
};
