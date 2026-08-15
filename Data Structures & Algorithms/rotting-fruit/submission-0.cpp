class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int, int>> q;
        int fresh = 0;
        int time = 0;

        for(int i = 0; i <grid.size(); i++)
        {
            for(int j = 0; j < grid[i].size(); j++)
            {
                if(grid[i][j] == 2)
                {
                    q.push({i, j});
                }

                else if(grid[i][j]==1)
                    fresh++;
            }
        }

        while(!q.empty() && fresh > 0)
        {
            int size = q.size();
            while(size--)
            {
                auto val = q.front();
                q.pop();
                int r = val.first;
                int c = val.second; 

                if(r-1 >= 0)
                {
                    if(grid[r-1][c] == 1)
                    {
                        grid[r-1][c] = 2;
                        q.push({r-1, c});
                        fresh--;
                    }
                }

                if(c-1 >= 0)
                {
                    if(grid[r][c-1] == 1)
                    {
                        grid[r][c-1] = 2;
                        q.push({r, c-1});
                        fresh--;
                    }
                }

                if(r+1 < grid.size())
                {
                    if(grid[r+1][c] == 1)
                    {
                        grid[r+1][c] = 2;
                        q.push({r+1, c});
                        fresh--;
                    }
                }

                if(c+1 < grid[r].size())
                {
                    if(grid[r][c+1] == 1)
                    {
                        grid[r][c+1] = 2;
                        q.push({r, c+1});
                        fresh--;
                    }
                }
            }
            time++;
        }

        if(fresh != 0)
            return -1;
        return time;
    }
};
