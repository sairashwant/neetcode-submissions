class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        
        vector<int> diff(gas.size());
        int total = 0; int lastindex;

        for(int i = 0; i < gas.size(); i++)
        {
            diff[i] = gas[i] - cost[i];
            total = total + diff[i];
        }

        if(total < 0)
            return -1;

        total = 0;
        lastindex = 0;

        for(int i = 0; i < gas.size(); i++)
        {
            total = total + diff[i];

            if(total < 0)
            {
                total = 0;
                lastindex = i+1;
            }
        }

        return lastindex;
    }
};
