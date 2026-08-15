class Solution {
public:
    string reorganizeString(string s) {
        
        unordered_map<char, int> count;
        priority_queue<pair<int, char>> maxHeap;
        
        for(auto ch : s)
        {
            count[ch]++;
        }

        for(auto c : count)
        {
            if(c.second > 0)
                maxHeap.push({c.second, c.first});
        }

        string result = "";
        pair<int, char> prev = {0, ' '};
        
        while(!maxHeap.empty() || prev.first > 0)
        {

            if(prev.first > 0 && maxHeap.empty())
                return "";

            auto temp = maxHeap.top();
            int count = temp.first;
            int ch = temp.second;

            maxHeap.pop();
            result += ch;
            count--;

            if(prev.first > 0)
                maxHeap.push(prev);

            prev = make_pair(count, ch);
        }

        return result;
    }
};