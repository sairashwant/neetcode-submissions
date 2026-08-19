class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
    
    if(hand.size()%groupSize != 0)
        return false;

    unordered_map<int, int> map;

    for(int num : hand)
        map[num]++;
        
    sort(hand.begin(), hand.end());

    for(auto num : hand)
    {
        if(map[num] > 0)
        {
            for(int i = num; i < num+groupSize; i++)
            {
                if(map[i] != 0)
                    map[i]--;
                
                else
                    return false;
            }
        }
    }

    return true;
    }
};
