class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
               
        priority_queue<pair<int, char>> maxHeap;

        if(a > 0)
        maxHeap.emplace(make_pair(a, 'a'));
        if(b > 0)
        maxHeap.emplace(make_pair(b, 'b'));
        if(c > 0)
        maxHeap.emplace(make_pair(c, 'c'));

        string result;

        while(!maxHeap.empty())
        {
            auto [count, ch] = maxHeap.top();
            maxHeap.pop();

            if(result.length() > 1 && result[result.length() - 1] == ch && result[result.length() - 2] == ch)
            {
                if(maxHeap.empty()) break;
                auto[count2, ch2] = maxHeap.top();
                maxHeap.pop();
                result += ch2;
                if(--count2 > 0) maxHeap.push({count2, ch2});
                maxHeap.push({count, ch});
            }
            else
            {
                result += ch;
                if(--count > 0) maxHeap.push({count, ch});
            }
        }

        return result;
    }
};