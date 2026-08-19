class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        
        int islands = 0;

        for(int i = 0; i < grid.size(); i++)
        {
            for(int j = 0; j < grid[i].size(); j++)
            {
                if(grid[i][j] == '1')
                    {
                        islands++;
                        bfs(grid, i, j);
                        
                    }
            }
        }

        return islands;
    }

    void bfs(vector<vector<char>>& grid, int r, int c)
    {
        queue<pair<int, int>> q;

        grid[r][c] = '0';

        q.push({r, c});

        while(!q.empty())
        {
            auto pair = q.front();
            q.pop();
            int i = pair.first;
            int j = pair.second;

            if(i-1>=0)
                if(grid[i-1][j] == '1')
                    {
                        q.push({i-1, j});
                        grid[i-1][j] = '0';
                    }

            if(i+1 < grid.size())
                if(grid[i+1][j] == '1')
                    {
                        q.push({i+1, j});
                        grid[i+1][j] = '0';
                    }

            if(j-1>=0)
                if(grid[i][j-1] == '1')
                    {
                        q.push({i, j-1});
                        grid[i][j-1] = '0';
                    }

            if(j+1 < grid[i].size())
                if(grid[i][j+1] == '1')
                    {
                        q.push({i, j+1});
                        grid[i][j+1] = '0';
                    }
        }
    }
};
