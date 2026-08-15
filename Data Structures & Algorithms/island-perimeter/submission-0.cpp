class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        
        for(int i = 0; i < grid.size(); i++)
        {
            for(int j = 0; j < grid[i].size(); j++)
            {
                if(grid[i][j] == 1)
                    {
                        int peri = bfs(grid, i, j);
                        return peri;
                    }
            }
        }

        return -1;
    }

    int bfs(vector<vector<int>>& grid, int r, int c)
    {
        queue<pair<int, int>> q;

        q.push({r,c});

        grid[r][c]=-1;

        int peri = 0;

        while(!q.empty())
        {
            auto index = q.front();
            q.pop();

            int i = index.first;
            int j = index.second;

            if(i+1 >= grid.size() || grid[i+1][j]==0)
                peri++;

            if(j+1 >= grid[i].size() || grid[i][j+1]==0)
                peri++;

            if(i-1 < 0 || grid[i-1][j]==0)
                peri++;

            if(j-1 < 0 || grid[i][j-1]==0)
                peri++;

            if(i+1 < grid.size() && grid[i+1][j] == 1)
            {
                grid[i+1][j]=-1;
                q.push({i+1,j});
            }

            if(j+1 < grid[i].size() && grid[i][j+1] == 1)
            {
                grid[i][j+1]=-1;
                q.push({i,j+1});
            }

            if(i-1 >= 0 && grid[i-1][j] == 1)
            {
                grid[i-1][j]=-1;
                q.push({i-1, j});
            }

            if(j-1 >= 0 && grid[i][j-1] == 1)
            {
                grid[i][j-1]=-1;
                q.push({i, j-1});
            }
        }
        

        return peri;
    }
};