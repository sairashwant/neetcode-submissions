class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        
        priority_queue<pair<int,int>, vector<pair<int, int>>, greater<pair<int, int>>> q;

        for(int i = 0; i < points.size(); i++)
        {
            long dist = (pow(points[i][0] - 0,2) + pow(points[i][1] - 0,2));
            q.emplace(dist, i);
        }

        vector<vector<int>> result;

        while(k != 0 && (!q.empty()))
        {
            auto i = q.top();
            int index = i.second;
            result.push_back(points[index]);
            q.pop();
            k--;
        }
        return result;
    }
};
