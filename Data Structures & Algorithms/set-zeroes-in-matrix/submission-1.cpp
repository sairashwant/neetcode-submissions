class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        unordered_set<int> zeroRowIndex;
        unordered_set<int> zeroColIndex;

        for(int i = 0; i < matrix.size(); i++)
        {
            for(int j = 0; j < matrix[i].size(); j++)
            {
                if(matrix[i][j] == 0)
                    {
                        zeroRowIndex.insert(i);
                        zeroColIndex.insert(j);
                    }
            }
        }

        for(int i = 0; i < matrix.size(); i++)
        {
            for(int j = 0; j < matrix[i].size(); j++)
            {
                if(zeroRowIndex.find(i) != zeroRowIndex.end())
                    matrix[i][j] = 0;
                
                if(zeroColIndex.find(j) != zeroColIndex.end())
                    matrix[i][j] = 0;
            }
        }

    }
};
