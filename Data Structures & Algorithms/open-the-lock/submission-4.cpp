class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        
        if(target == "0000") return 0;

        unordered_set<string> visit(deadends.begin(), deadends.end());

        if(visit.find("0000") != visit.end()) return -1;

        queue<string> q;
        q.push("0000");
        visit.insert("0000");
        int steps = 0;

        while(!q.empty())
        {
            steps++;
            int levelSize = q.size();
            
            for(int i = 0; i < levelSize; i++)
            {
                string lock = q.front(); 
                q.pop();
            
                for(int j = 0; j < 4; j++)
                {
                    for(int move : {1, -1})
                    {
                        string nextLock = lock;
                        nextLock[j] = (((lock[j] - '0') + move + 10) % 10) + '0';
                        if(visit.count(nextLock)) continue;
                        if(nextLock == target) return steps;
                        q.push(nextLock);
                        visit.insert(nextLock);
                    }
                }
            }
        }

        return -1;
    }
};