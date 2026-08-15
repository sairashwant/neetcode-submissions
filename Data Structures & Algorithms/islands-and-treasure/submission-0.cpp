class Solution {
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
                
        for(int i = 0; i < grid.size(); i++)
        {
            for(int j = 0; j < grid[i].size(); j++)
            {
                if(grid[i][j]==2147483647)
                    {
                        int dist = bfs(grid, i, j);
                        if(dist!=-1)
                            grid[i][j] = dist;
                    }
            }
        }

        return;
    }

    int bfs(vector<vector<int>> &grid, int r, int c)
    {
        queue<pair<int, int>> q;
        q.push({r, c});
        vector<pair<int,int>> visited;
        int dist = 0;
        visited.push_back({r, c});

        while(!q.empty())
        {
            int sz = q.size();
            for(int t = 0; t < sz; t++)
            {
            auto val = q.front(); q.pop();
            int row = val.first;
            int col = val.second;

            if(grid[row][col] == 0)
                {
                    return dist;
                }

            if(row-1 >= 0)
                {
                    if((grid[row-1][col] != -1) && 
                    find(visited.begin(), visited.end(), make_pair(row-1, col)) == visited.end())
                        {
                            q.push({row-1, col});
                            visited.push_back({row-1, col});
                        }
                }

            if(col-1 >= 0)
                {
                    if((grid[row][col-1] != -1) && find(visited.begin(), visited.end(), make_pair(row, col-1)) == visited.end())
                    {
                        q.push({row, col-1});
                        visited.push_back({row, col-1});
                    }
                }
            
            if(row+1 < grid.size())
                {
                    if((grid[row+1][col] != -1) && find(visited.begin(), visited.end(), make_pair(row+1, col)) == visited.end())
                    {
                        q.push({row+1, col});
                        visited.push_back({row+1, col});
                    }
                }
                

            if(col+1 < grid[row].size())
                {
                    if((grid[row][col+1] != -1) && find(visited.begin(), visited.end(), make_pair(row, col+1)) == visited.end())
                    {
                        q.push({row, col+1});
                        visited.push_back({row, col+1});
                    }
                }
            
            
            }
            dist++;
        }

        return -1;
    }
};
