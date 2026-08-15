class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int j = 0;
        for(int i = 0; i < matrix.size(); i++)
        {
            j = matrix[i].size()-1;
            if( matrix[i][j] < target)
                continue;
            
            int beg = 0;
            int end = matrix[i].size()-1;
            int mid = (beg+end)/2;

            while(beg <= end)
            {
                mid = (beg+end)/2;
                if(matrix[i][mid] < target)
                {
                    beg = mid + 1;
                }
                else if(matrix[i][mid] > target)
                {
                    end = mid - 1;
                }
                else
                    {
                        cout<<"i: "<<i<<" "<<"j: "<<j;
                        return true;
                    }
            }
        }

        return false;
    }
};
