class Solution {
public:
    set<pair<int, int>> path;

    bool exist(vector<vector<char>>& board, string word) {
        
        for(int i = 0; i < board.size(); i++)
        {
            for(int j = 0; j < board[i].size(); j++)
            {
                if(board[i][j] == word[0])
                {
                    if(dfs(board, word, i, j, 0)) 
                        return true;
                }
            }
        }

        return false;
    }

    bool dfs(vector<vector<char>>& board, string word, int i, int j, int k)
    {
        if(k == word.length())
            return true;

        if(i >= board.size() || j >= board[i].size() || i < 0 || j < 0 || board[i][j] != word[k] || 
        path.count({i, j}))
            return false;
        
        path.insert({i, j});
        bool res = dfs(board, word, i+1, j, k+1) ||
        dfs(board, word, i, j+1, k+1)||
        dfs(board, word, i-1, j, k+1)||
        dfs(board, word, i, j-1, k+1);
        path.erase({i, j});

        
        return res;
    }
};
